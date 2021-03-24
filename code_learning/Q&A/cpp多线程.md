# 多线程


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
```
**注意**:使用pthread需要先init，再使用，否则无效；std::mutex可以直接使用，不需要init.