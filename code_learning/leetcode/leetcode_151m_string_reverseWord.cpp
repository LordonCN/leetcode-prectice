#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* -------------------------------------------
 * 前面添加用+号 roman = "string" + roman;
 * ------------------------------------------*/

string reverseWord(string s)
{
    // 准备工作
    string returnString;
    string outputString; // 接收
    int length = s.length();
    stack<char> stackChar;

    for(int i = 0; i <= length; i++)
    {
        // 如果开头为空格 什么也不做 || 中间有多的空格 消掉
        if(s[i] == ' ' && stackChar.empty()) ;
        // 如果遇到中间的空格 那么将他取出来放到待拼接字符串中 并且清空栈
        else if(s[i] == ' '){
            while(!stackChar.empty())
            {
                outputString = stackChar.top() + outputString;
                stackChar.pop();
            }
            outputString  = s[i] + outputString;
            // 字符串拼接
            returnString = outputString + returnString;
            outputString = "";
        }
        // 最后不是以空格结束
        else if(i == length){
            while(!stackChar.empty())
            {
                outputString = stackChar.top() + outputString;
                stackChar.pop();
            }
            // 字符串拼接
            returnString = outputString + returnString;
            outputString = "";
        }
        else{
            stackChar.push(s[i]);
        }
    }

    return returnString;
}

int main()
{
    string s = "i   s is m";

    // 特殊情况判断
    if (s.empty()) return 0;

    s = reverseWord(s);
    cout<<s<<endl;

    return 0;
}




