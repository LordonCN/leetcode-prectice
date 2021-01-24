#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;
/*************************************************************************
 * INPUT:   charList ""
 *                                                                                    *
 * OUTPUT:  whether it is empty
 *                                                                                    *
 * WARNINGS:  special situation
 *                                                                                    *
 * HISTORY:  use char
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


int main()
{
//    queue<int>intNumberQueue;
//    queue<int>intNumberQueue_1;
//    cout<<"The state of numberqueue is :"<<intNumberQueue.empty()<<endl;
//    intNumberQueue.push(199);
//    cout<<"The state of numberqueue is :"<<intNumberQueue.empty()<<endl;
//    intNumberQueue.push(23);
//    intNumberQueue.push(89);
//    intNumberQueue.push(23);
//    intNumberQueue.push(12);
//    cout<<"The size of queue is :"<<intNumberQueue.size()<<endl;
//
//    intNumberQueue.swap(intNumberQueue_1);
//
//    cout<<"The state of numberqueue is :"<<intNumberQueue.empty()<<endl;
//    cout<<"The first one is :"<<intNumberQueue_1.front()<<endl;
//



    char* charList = "{}"; // char 类型 指针定义 双引号包含内容
    charStack(charList);


    return 0;
}