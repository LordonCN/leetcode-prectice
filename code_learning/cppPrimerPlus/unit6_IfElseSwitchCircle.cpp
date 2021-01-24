#include <iostream>

int main()
{
    using namespace std;

    // rule1: if-else 还有其他循环 都要加{} 代码规划性
    int ifTestNumber = 0;
    if (ifTestNumber!=0)
    {
        cout<<"hahah"<<endl;
    }
    else
    {
        cout<<"xixixi"<<endl;
    }




    // rule2: 判断是否相等的时候将变量variable 置于末尾 能够避免判断相等时错误使用赋值语句
    int variableNumberTest = 10;
    if(11 == variableNumberTest)
    {
        cout<<"yes"<<endl;
    }
    else if (10 == variableNumberTest)
    {
        cout<<"no"<<endl;
    }
    else
    {
        cout<<"hahah"<<endl;
    }




    // 逻辑表达式 || && !
    // TODO:?: 条件运算符 很重要
    5<3? cout<<"yes"<<endl : cout<<"no"<<endl;
    



    // switch 用法
    int choiceNumber = 10;
    switch(choiceNumber)
    {
        case 1:cout<<"1";
        case 10:cout<<"yes";
        default:cout<<"default"; 
    }




    //stop for a while
    int stopForAwhile;
    cout<<endl;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stopForAwhile;

    return 0;
}