# 类中三个类型有何区别

正常情况下所有的`public` 方法、成员均可以进行访问。

派生类中 protected 方法、成员只有`通过类中的公有方法`可以访问.(不知道该怎么描述)

[参考](https://blog.csdn.net/liyuanbhu/article/details/72858776)

```c++
#include <iostream>
#include <numeric>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <memory>
#include <vector>

using namespace std;

class Fruit{
public:
    void print(){cout<<a<<endl;};
    void printb(){cout<<b<<endl;};
    
protected:
    int b = 0;
    
private:
    int a = 0;
};

class Apple:public Fruit{
public:
    void change(){Fruit::b = 1;};
    // 这里参考下面的链接 
    //https://blog.csdn.net/liyuanbhu/article/details/72858776
    void init(){b = 11;};// 类内公有方法调用保护成员 不能给a赋值
};

int main()
{
    Fruit* A = new Fruit;
    A->print();
    Apple* B = new Apple;
    B->change();
    B->init();
    A->printb();
    
    return 0;
}


```


- 使用xcode调试显示B类型为：
```c++
A
 a
 b
-----------------
B 
 Fruit
      a
      b
```
可以看出在B中是可以使用作用域解析运算符直接赋值的，这也可以结合`多继承`来理解；
同时`公有继承`的`私有成员`是不可访问的，只能对`公有成员`与`保护成员`操作。

