#include <iostream>
#include <string>
#include <cstring>
// 包含头文 注意路径的写法 之后的养成习惯 函数以结构体都写到本单元的头文件中
#include "structs.h"

// 头文件中定义后直接用来初始化
TestStruct testOne 
{
    "fko123ls",
    1,
    "fksdl"
};
Inflatable guest =
{
    "Gisjkljflsjfd",
    1.88,
    2.34
};
Inflatable pal =
{
    "ksjfdlksjlfdjls",
    0.88,
    2.4
};

//共用体测试 怎么不是自动转换数据执行呢 j竟然是给我销毁了
union oneDataInFourType
{
    int intType;
    double doubleTpye;
    char charType;
    bool boolType;
} fourTypeTest;

int main()
{

    using namespace std;
    Inflatable peopleZhang = {"yunfei",1234.12,2.3};

    Inflatable peopleXu;
    // 此结构体j字符赋值需要通过strcp进行 
    // peopleXu.name = "hello";
    strcpy(peopleXu.name,"luodong");
    peopleXu.price = 1.2;
    peopleXu.doubleType= 3;

    cout<<"guest.name is:"<<guest.name<<endl;
    cout<<"pal.price is:"<<pal.price<<endl;
    cout<<"test_one.name is:"<<testOne.name<<endl;
    cout<<"peopleXu.price is:"<<peopleXu.price<<endl;
    cout<<"peopleXu.price is "<<peopleXu.name<<endl;
    // 匿名共用体
    cout<<"peopleXu.inttype is "<<peopleXu.intType<<endl;
    cout<<"peopleXu.doubletype is "<<peopleXu.doubleType<<endl;

    // 共用体测试 
    fourTypeTest.intType = 4;
    cout<<"fourTypeTest is:"<<fourTypeTest.intType<<endl;
    cout<<"fourTypeTest is:"<<fourTypeTest.doubleTpye<<endl;
    fourTypeTest.doubleTpye= 3.4;
    cout<<"fourTypeTest is:"<<fourTypeTest.intType<<endl;
    cout<<"fourTypeTest is:"<<fourTypeTest.doubleTpye<<endl;
    
    //stop for a while
    int stopForAwhile;
    cout<<endl;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stopForAwhile;

    return 0;
}