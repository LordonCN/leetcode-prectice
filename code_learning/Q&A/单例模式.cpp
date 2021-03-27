#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * *
 * 单例模式 不使用指针进行构造 否则能够引起内存泄露
 * 参考：
 * https://www.bilibili.com/video/BV1Gz4y1d7RJ
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * */


class SingletonPointer{
public:
    ~SingletonPointer(){
        cout<<"this is xigouhanshu"<<endl;

    }
    static SingletonPointer* CreatObject(){
        return new SingletonPointer;
    };

private:
    SingletonPointer(){
        cout<<"this is gouzaohsnashu "<<endl;
    };
};

class Singleton{
public:
    ~Singleton(){
        cout<<"this is xigouhanshu"<<endl;
    }
    static Singleton& CreatObject(){
        static Singleton obj;
        return obj;
    };

private:
    Singleton(){
        cout<<"this is gouzaohsnashu "<<endl;
    };
};

int main()
{
//    Singleton& name1 = Singleton::CreatObject();
//    Singleton& name2 = Singleton::CreatObject();
    SingletonPointer* obj1 = SingletonPointer::CreatObject();
    delete obj1;

    return 0;
}