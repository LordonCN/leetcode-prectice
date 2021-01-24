#include <iostream>
// 定义常量用来初始化后面的 多维数组
// 使用双循环对数组进行遍历 
// 数组与指针的运用
// 提高：unit17介绍 输出格式化 更精确 更复杂

const int citysNumber = 4;
const int yearsRange = 3;

int (*fun(int(&a)[3][3]))[3];


// 测试继承类能否打印
class Test{
private:
    int number = 100;

public:
    void responce();
    int printfname(){return number;};
};

class oneTest:public Test{
public:
    // 直接公有继承 接口实现基类私有参数的访问
};

class twoTest:Test{
public:
    void printhello2(){std::cout<<privateTest.printfname()<<std::endl;};
private:
    Test privateTest;
};

int main()
{
    using namespace std;
    // 指针数组特点是 存储空间小 更加经济好用
    // 缺点是不易修改 使用二维数组容易修改


    oneTest test1;
    cout<<test1.printfname()<<endl;
    twoTest test2;
    test2.printhello2();




    const char* cityPointer[citysNumber]=
    {
        "Shandong",
        "Liaoning",
        "Beijing",
        "Tianjin"
    };
    // cout<<cityPointer[3]<<endl;
    // string类型的数组
    const string cityStringArray[citysNumber]=
    {
        "Shandong",
        "Liaoning",
        "Beijing",
        "Tianjin"
    };

    int yearFinancialIncomes[citysNumber][yearsRange]=
    {
        {34,23,45},
        {123,34,56},
        {23,4,3},
        {23,34,45}
    };


    for(int _ = 0; _ < citysNumber; _++)
    {
        cout<<cityPointer[_];
        for(int j = 0; j < yearsRange; j++)
        {
            cout<<" "<<yearFinancialIncomes[_][j]<<" ";
        }
        cout<<endl;
    }


    Test test_1[2]; 
    cout<<"this is test one cout "<<test_1<<endl;

    // int(*p)[3];
    // cout<<p<<endl;
    // // 增加了12
    // cout<<p+1<<endl;
    // cout<<*p<<endl;
 
    // int  var[3] = {10, 100, 200};
    // int *ptr[3];
  
    // for (int i = 0; i < 3; i++)
    // {
    //    ptr[i] = &var[i]; // 赋值为整数的地址
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //    cout << "Value of var[" << i << "] = ";
    //    cout << *ptr[i] << endl;
    // }   
 



    int a[3][3] = {{1,2,3},{2,0,1},{3}};
    int (*p)[3] = &a[0]; 
    // int (*fun(int(&a)[3][3]))[3];

    cout<<a<<"==";
    cout<<p<<" is"<<a[0][0]<<endl;

    cout<<a+1<<"==";
    cout<<p+1<<" is"<<a[0][1]<<endl;
    
    cout<<*p<<endl;
    cout<<p+1<<endl;
    cout<<*(p+1)<<endl;

    //stop for a while
    int stopForAwhile;
    cout<<endl;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stopForAwhile;



    return 0;
}