#include <iostream>
#include <string>
#include <cstring>

#include <vector>
#include <ctime>
#include <array>
// 别名命名法 建议第二种
#define BYTE char
// good 选他！
typedef char byte;

// 四种循环 for while do-while range-for
int main()
{
    using namespace std;
 
    string word;
    // 用于键入字符串
    // cin>>word;
    for(int i = 0;i<5;i++)
    {
        cout<<"It's curcling"<<endl;
    }


    int guests = 1;
    while(guests++<10)
    {
        cout<<guests<<endl;
    }
    // strcmp 比较字符串 不一样则返回1
    cout<<"test strcmp func"<<strcmp("hello","hallo")<<endl;


    int doWhileNumber;
    do
    {
        cout<< "input 7 to stop while"<<endl;
        cin>>doWhileNumber;
        // 如果不为7就一直输入
    } while (doWhileNumber!=7);
    



    // 基于范围的for循环 特别是对于数组 比如 容器类 进行的操作
    double forRange[] {1.2,2.2,3.4,5.6,7.5};
    for(double _ : forRange)
    {
        cout<<_<<endl;
    }
















    //stop for a while
    int stopForAwhile;
    cout<<endl;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stopForAwhile;


    return 0;
}