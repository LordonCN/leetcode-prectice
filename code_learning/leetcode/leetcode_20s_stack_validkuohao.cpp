#include <iostream>
#include <string>
#include <stack> // 本身就是一个模板类
using namespace std;

/*************************************************************************
 * INPUT:   charList ""
 *                                                                                    *
 * OUTPUT:  whether it is empty
 *                                                                                    *
 * WARNINGS:  special situation
 *                                                                                    *
 * HISTORY:  use char 外部循环靠指针所指向数值进行判断 while循环
 *======================================================================*/
void charStack(char *charList)
{
    stack<char>charStack; // char类型 栈创建

    // 指针可以作为遍历条件 超出长度即为"\0" 或者""
    // *指针可以作为便利条件 超出长度即为空 while(*charList)
    while(*charList)
    {
        // 取所指向符号
        switch(*charList) // 取
        {
            // 如果左括号就入栈
            case '{' : charStack.push(*charList);break;
            case '[' : charStack.push(*charList);break;
            case '(' : charStack.push(*charList);break;
            case '}' :
                if('{' == charStack.top()){
                    charStack.pop();break;
                }
                else {
                    charStack.push(*charList);
                    break;
                }
            case ']' :
                if('[' == charStack.top()){
                    charStack.pop();break;
                }
                else {
                    charStack.push(*charList);
                    break;
                }
            case ')' :
                if('(' == charStack.top()){
                    charStack.pop();break;
                }
                else{
                    charStack.push(*charList);break;
                }
            default: // pointer = ""
                break;
        }
        charList += 1;

    }
    if(!charStack.empty())
        cout<<"no!!"<<endl;
    else
        cout<<"yes!!"<<endl;

}

/*************************************************************************
 * INPUT:   stringList ""
 *                                                                                    *
 * OUTPUT:  whether it is empty
 *                                                                                    *
 * WARNINGS:  special situation
 *                                                                                    *
 * HISTORY:  use string string可以使用size()求得总长度 直接循环遍历即可
 *======================================================================*/
void stringStack(string stringList)
{
    stack<char>stringStack;
    int len = stringList.size();
    for(int i = 0;i < len;i ++)
    {
        switch(stringList[i])
        {
            case '(' :stringStack.push(stringList[i]);break;
            case '[' :stringStack.push(stringList[i]);break;
            case '{' :stringStack.push(stringList[i]);break;
            case ')' :
                if('(' == stringStack.top())
                    stringStack.pop();
                else
                    stringStack.push(stringList[i]);
                break;

            case '}' :
                if('{' == stringStack.top())
                    stringStack.pop();
                else
                    stringStack.push(stringList[i]);
                break;

            case ']' :
                if('[' == stringStack.top())
                    stringStack.pop();
                else
                    stringStack.push(stringList[i]);
                break;
            default:
                break;
        }
    }

    if(!stringStack.empty())
        cout<<"no!!"<<endl;
    else
        cout<<"yes!!"<<endl;

}

int main()
{
//    char* charList = "{}"; // char 类型 指针定义 双引号包含内容
//    charStack(charList);


    // 使用string 并且加入stack模板
    string stringList ="()";
    stringStack(stringList);


    return 0;
}