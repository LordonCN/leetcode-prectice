# 多线程

[stop at 3.3 part](https://github.com/xiaoweiChen/CPP-Concurrency-In-Action-2ed-2019/blob/master/content/chapter3/3.3-chinese.md)

TODO: 
question：unique_lock怎么灵活了 ，看例子就是使用顺序不同


### 死锁
原因：其中每个线程都有一个互斥量，且等待另一个解锁。
因为他们都在等待对方先释放互斥量，导致没有线程能正常工作。
这种情况就是死锁，它的问题就是由两个或两个以上的互斥量进行锁定,导致无法正常运行。

- 死锁是多线程编程中令人相当头痛的问题，并且死锁经常是不可预见的，
  因为在大部分时间里，所有工作都能很好的完成。
  不过，一些相对简单的规则能帮助写出“无死锁”的代码。

死锁通常是对锁的使用不当造成。
无锁的情况下，仅需要两个线程std::thread对象互相调用join()就能产生死锁。
这种情况下，没有线程可以继续运行，因为他们正在互相等待。
这种情况很常见，一个线程会等待另一个线程，其他线程同时也会等待第一个线程结束，所以三个或更多线程的互相等待也会发生死锁。
为了避免死锁，这里意见：不要谦让。以下提供一些个人建议。

### 怎么样避免死锁
1. 当线程获得一个锁时，就别再去获取第二个。如果`每个线程`只持有`一个锁`，那么就不会产生死锁。

2. 当线程内部需要`获取多个锁`，使用`std::lock(lhs.m,rhs.m)`对获取锁的操作上锁,配合std::adopt_lock交出权限，避免产生死锁。

3. 当线程需要获取多个锁且不能使用lock，就要 在每个线程上用`固定的顺序获取`多个锁,或者使用`层级锁`，让其自动判断。
   (比如在项目中不能使用std::lock时，在机器人控制的时候都是pthread,修改起来难度太高，那么久要注意按照固定的顺序来获取锁)

### join detach
```c++
    if(my_thread.joinable())
        my_thread.detach();// 不等待线程结束直接停止  除非十分确定已经结束 否则需要加join等待运行结束
        
    if(my_thread.joinable())
        my_thread.join();// 否则需要加join等待运行结束
```
**注意**

1 thread执行过一次join与detach之后再调用会出错，所以加一个joinable判断。

2 一般都是用join()保证主进程会在其他线程之后才结束。

### 为了线程安全执行提出了`保安类`
```c++
class thread_guard
{
    std::thread& t;
public:
    // 防止构造函数执行隐式转换
    explicit thread_guard(std::thread& t_):
        t(t_)
    {}
    // 类中析构函数进行等待结束，防止误操作
    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();// 放到析构函数中 更加保险
        }
    }
    // 禁止拷贝构造函数
    thread_guard(thread_guard const&)=delete;
    // 禁止复制运算符
    thread_guard& operator=(thread_guard const&)=delete;
};

int main()
{
    thread txd(func);
    thread_guard txdg(txd);// 将线程传入该类即可保证在释放此类的时候能等待线程结束
}
```
注意：
保安类作为模板可以直接用，该泪在设计中加入了`防止隐式转换explicit`与`禁止拷贝`跟`复制运算符`的使用，很`细节`。


### 与保安类相似的的 权限转移保安类型 通过移动线程权限来防止传入线程再次获得权限报错
```c++
class scoped_thread
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_):
        t(std::move(t_))
    {
        if(!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread()
    {
        t.join();
    }
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};
```



### 经典应用场景:应用多开
让同一个应用的多个窗口同时运行，不用管其他是否运行结束，所以每个任务都是独立运行在新的线程上。


### 参数传入需要用，隔开
```c++
    thread t(func,param1,..paramn);
```

### 线程的所有权跟unique_ptr一样是可以移动的
因为一个线程的任务不可以与其他线程共享，其原理同unique_ptr相同，所以在如果没有禁止
  拷贝构造函数的时候可以使用std::move进行权限转移。

### 使用vector管理同类线程
将std::thread放入std::vector是向线程自动化管理迈出的第一步：并非为这些线程创建独立的变量，而是把它们当做一个组。创建一组线程(数量在运行时确定)，而非代码2.8那样创建固定数量的线程。

### 加pthread_mutex_t进行锁住进程(小知识 pthread适用于UNIX平台，win的话还是用std::mutex)
```c++
// for UNIX
#include <vector>
#include <thread>
#include <functional>
#include <iostream>

pthread_mutex_t mtx;// 

// 打印结果乱七八糟是因为在打印过程中相互干扰了 这时候要加锁
void do_work(unsigned n)
{
    pthread_mutex_lock(&mtx);// 上锁 其他谁也不嗯能够打扰我输出
    std::cout<<" now is doing "<< n <<" work ."<<std::endl;
    pthread_mutex_unlock(&mtx);// 我好了
}

void f()
{
    pthread_mutex_init(&mtx, NULL);// 注意；要先初始化 否则虽然不报错，但是不起作用

    // 批量创建线程 vector存储
    std::vector<std::thread> threads;
    for(unsigned i=0;i<20;++i)
        threads.push_back(std::thread(do_work,i));
    // 线程组同时进行调用时为了防止相互干扰需要加锁保证内部稳定执行
    for(auto &each : threads)
        each.join();
}

int main()
{
    f();
}

// for WINDOWS
#include <mutex>
mutex mtx;
void do_work(unsigned n)
{
    mtx.lock();// 全局声明之后直接用
    std::cout<<" now is doing "<<n<<"work ."<<std::endl;
    mtx.unlock();
}

void f()
{
    std::vector<std::thread> threads;
    for(unsigned i=0;i<20;++i)
    threads.push_back(std::thread(do_work,i));
    for(auto &each : threads)
    each.join();
}

int main()
{
    f();
}

// 提高稳定性  使用lock_guard进行智能加锁
void add_to_list(int value)
{
    // lock_guard能够
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(value);
}
```
**注意**:使用pthread需要先init，再使用，否则无效；std::mutex可以直接使用，不需要init.

### 线程安全的锁可以加在标准库外 比如thread_stack

在std::stack外加了一层线程安全的保护锁

```c++
#include <exception>
#include <stack>
#include <mutex>
#include <memory>

// 线程安全的栈使用方法
// 在std::stack外加了一层线程安全的保护锁

struct empty_stack: std::exception// 异常抛出
{
    const char* what() const throw()
    {
        return "empty stack";
    }
};

template<typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m; // mutable声明变量并非类内部状态
public:
    threadsafe_stack(){}// 默认构造函数
    threadsafe_stack(const threadsafe_stack& other)// 拷贝构造函数
    {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop()//std::shared_ptr可以避免内存分配管理的问题
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=data.top();
        data.pop();
    }
    bool empty() const//与mutable相对应
    {
        std::lock_guard<std::mutex> lock(m);/*在类函数为const状态时仍然能使用该锁*/
        return data.empty();
    }
};

int main()
{
    threadsafe_stack<int> si;
    si.push(5);
    si.pop();
    if(!si.empty())
    {
        int x;
        si.pop(x);
    }
    
}
```
**注意**：这里涉及mutable锁的使用，小细节。
throw函数为结构体中定义的一种返回方法，    

### 层级锁 根据不同层级来判断上锁先后顺序
```c++
class hierarchical_mutex
{
    std::mutex internal_mutex;
    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    static thread_local unsigned long this_thread_hierarchy_value;

    void check_for_hierarchy_violation()
    {
        if(this_thread_hierarchy_value <= hierarchy_value)
        {
            throw std::logic_error("mutex hierarchy violated");
        }
    }
    void update_hierarchy_value()
    {
        previous_hierarchy_value=this_thread_hierarchy_value;
        this_thread_hierarchy_value=hierarchy_value;
    }
public:
    explicit hierarchical_mutex(unsigned long value):
        hierarchy_value(value),
        previous_hierarchy_value(0)
    {}
    void lock()
    {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }
    void unlock()
    {
        this_thread_hierarchy_value=previous_hierarchy_value;
        internal_mutex.unlock();
    }
    bool try_lock()
    {
        check_for_hierarchy_violation();
        if(!internal_mutex.try_lock())
            return false;
        update_hierarchy_value();
        return true;
    }
};
```

### lock_guard
```c++
    friend void swap(X& lhs, X& rhs)
    {
        if(&lhs==&rhs)
            return;
        std::lock(lhs.m,rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock);// 已经锁上 但是权力交出去
        std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock);
        swap(lhs.some_detail,rhs.some_detail);
    }
```

### unique_lock (所有权可转移 注意是std::move)
```c++
    friend void swap(X& lhs, X& rhs)
    {
        if(&lhs==&rhs)
            return;
        std::unique_lock<std::mutex> lock_a(lhs.m,std::defer_lock);// 未被锁住的
        std::unique_lock<std::mutex> lock_b(rhs.m,std::defer_lock);
        std::lock(lock_a,lock_b);// 在这里上锁
        swap(lhs.some_detail,rhs.some_detail);
    }
```
**注意**：相对lock_guard来说，unique_lock更加灵活，但是效率低。







