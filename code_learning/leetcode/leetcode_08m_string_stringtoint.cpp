#include <iostream>
#include <string>
#include <stack> // 本身就是一个模板类
using namespace std;

// 正常遍历 思维 解法1

int main()
{
    string s= " -452jk"; // 双引号跟单引号到底有什么区别  单引号是字符？？？
    int numberChar = 0;
    int length = s.length();
    bool positive = true;

    // 特殊情况判断
    if (s.empty())
        return 0;

    // 循环遍历
    string s_;
    while(numberChar < length)
    {
        // 跳过空格
        if(' ' == s[numberChar]){
        }
        // 检测到字母立刻停止 包括返回0 跟 数字两种情况
        else if('a' < s[numberChar] && 'z'> s[numberChar])
            break;
        else if('-' == s[numberChar])
        {
            positive = '-' != s[numberChar]; // idea 自动简化 不如下面更直观
            // positive = ('-' == s[numberChar])?false : true;
        }
        else{
            s_.push_back(s[numberChar]);
        }
        numberChar += 1;
    }
    cout<<s_<<endl;

    // 需要进行string->int的转化 *1 *10 *100
    if(!positive) // 负数处理
    {}
    else // 正常
    {}

    return 0;
}







// 竟然一上来就想到的是倒着遍历 可能是考虑到string类似于python栈的性质
//// 倒序提取所有字符
//while(s != "")
//{
//if(s.back()==' ')
//s.pop_back();
//else
//{
//s_.push_back(s.back());
//s.pop_back();
//}
//}