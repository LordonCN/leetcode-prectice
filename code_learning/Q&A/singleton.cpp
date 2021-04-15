#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * *
 * 单例模式 不使用指针进行构造 否则能够引起内存泄露
 * 使用原因 ：
 * 当只能够存在一个对象的时候
 * 全局变量，大家应该都使用过，很好用。定义全局变量，项目各个地方都能使用，虽然好用，但是缺点也非常的明显，javaScript这种弱类型语言，
 * 变量和方法都暴露在全局中，很容易出现变量冲突，变量就会有被覆盖的风险，应该尽量避免使用全局变量。单例模式能解决这种问题。
 *
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
    static Singleton & CreatObject(){// 返回singleton类型的引用
        static Singleton obj;// 注意没有&符号 一直没记住 4.14
        return obj;
    };
private:
    Singleton(){cout<<"this is gouzaohsnashu "<<endl;};
    ~Singleton(){cout<<"this is xigouhanshu"<<endl;}
};
/*********************************************************/
// 懒汉模式
// 使用私有静态指针变量
class Singleton_pointer
{
private:
    static Singleton_pointer* instance;

    Singleton_pointer() {cout<<"this is pointer constractor"<<endl;};// 默认构造
    ~Singleton_pointer() {cout<<"this is pointer disconstractor";};
    Singleton_pointer(const Singleton_pointer&);           // 拷贝构造
    Singleton_pointer& operator=(const Singleton_pointer&);// 赋值构造 传回引用

    // 防止析构的办法 嵌套类对象 析构时调用deletor删除静态指针 消除唯一实例
    class Deletor {
    public:
        ~Deletor() {
            if(Singleton_pointer::instance != NULL)
            {
                delete Singleton_pointer::instance;
                cout<<"this is delete dis"<<endl;
            }
        }
    };
    static Deletor deletor;
public:

    static Singleton_pointer* getInstance()
    {
        if(instance == NULL)// 如果指针为空 单例未被创建
            instance = new Singleton_pointer();// 3.30记住这里是new出来的 不是生成了一个对象赋值
        return instance;
    }
};
                    // 作用类解释符   该指针在逻辑上与singletonp类相关 但不是它的成员
Singleton_pointer* Singleton_pointer::instance = NULL;// 3.30这里也没记住
Singleton_pointer::Deletor Singleton_pointer::deletor;
/*********************************************************/

int main()
{
    // 引用模式创建
    Singleton& name1 = Singleton::CreatObject();

    // 指针模式创建
    Singleton_pointer* obj1 = Singleton_pointer::getInstance();

    int a = 0;


    return 0;
}