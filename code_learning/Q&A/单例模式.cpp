#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * *
 * 单例模式 不使用指针进行构造 否则能够引起内存泄露
 * 使用原因 ： 当只能够存在一个对象的时候
 * 参考：
 * https://www.bilibili.com/video/BV1Gz4y1d7RJ
 *
 * The smaller, the better. I am a minimalist
 * Make sure it is thread safe
 * Make sure it is never null
 * Make sure it is created only once
 * TODO: 单例模式 涉及静态类方法 静态类私有变量用法
 * * * * * * * * * * * * * * * * * * * * */
/*********************************************************/
// 引用构造 更加优雅简洁
class Singleton{
public:
    static Singleton & CreatObject(){
        static Singleton obj;
        return obj;
    };
private:
    Singleton(){cout<<"this is gouzaohsnashu "<<endl;};
    ~Singleton(){cout<<"this is xigouhanshu"<<endl;}
};
/*********************************************************/
// 懒汉模式
// 使用私有静态指针变量
//
class Singleton_pointer
{
private:
    static Singleton_pointer* instance;
private:
    Singleton_pointer() {};
    ~Singleton_pointer() {};
    // 防止析构的办法 嵌套类对象 析构时调用deletor删除静态指针 消除唯一实例
    class Deletor {
    public:
        ~Deletor() {
            if(Singleton_pointer::instance != NULL)
                delete Singleton_pointer::instance;
        }
    };
    static Deletor deletor;
private:
    Singleton(const Singleton_pointer&);
    Singleton_pointer& operator=(const Singleton_pointer&);
public:
    static Singleton_pointer* getInstance()
    {
        if(instance == NULL)// 如果指针为空 单例未被创建
            instance = new Singleton_pointer();
        return instance;
    }
};

// init static member 很有必要
Singleton_pointer* Singleton_pointer::instance = NULL;
Singleton_pointer::getInstance();
/*********************************************************/

int main()
{
    Singleton& name1 = Singleton::CreatObject();

    Singleton_pointer* obj1 = Singleton_pointer::getInstance();
    delete obj1;

    return 0;
}