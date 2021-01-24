#include <iostream>
#include "listNode.h"
#include <stack>// stl::stack empty size push top 都是sequence直接实现的 所以会有题目要求用队列实现

using namespace std;
/*结构体初始化的时候用*跟不用到底有什么区别? */
#define Maxsize 100

// 顺序栈采用动态存储形式 即先创建一个大小固定的数组
struct SqStack{
   int data[Maxsize];
   int top = 0;
};

struct SqStack2{
    int* base;
    int top = 0;
};

void pop(SqStack *sqStack)
{
    // 顺序前移一位
    if(sqStack->top)
    {
        for(int i = 1; i< Maxsize;i++)
        {
            sqStack->data[i-1] = sqStack->data[i];
        }
        sqStack->top -= 1;
    }
    else
    {
        cout<<"warning stack is empty"<<endl;
    }
}

void push(SqStack *sqStack , int value)
{
   // 顺序后移一位 top用来判断是否装满
   if(sqStack->top<Maxsize-1)
   {
       for(int i =Maxsize-2;i >= 0; i--)
       {
           sqStack->data[i+1] = sqStack->data[i];
       }
   }
   sqStack->data[0] = value;
   sqStack->top += 1;
}

void push2(SqStack2 *sqStack , int value)
{
    // 顺序后移一位 top用来判断是否装满
    if(sqStack->top<Maxsize-1)
    {
        for(int i =Maxsize-2;i >= 0; i--)
        {
            sqStack->base[i+1] = sqStack->base[i];
        }
    }
    sqStack->base[0] = value;
    sqStack->top += 1;
}

int getTop(SqStack *sqStack)
{
    return sqStack->data[0];
}

bool isEmpty(SqStack *sqStack)
{
    if(sqStack->top)
        return false;
    else
        return true;
}

void ClientCode()
{
    // 静态栈
    SqStack *sqStack = new SqStack;
    push(sqStack,6);
    int topNumber = getTop(sqStack);
    cout<<topNumber<<"the length is :" << sqStack->top<<endl<<
    "is stack empty?"<< isEmpty(sqStack)<<endl;


    // 动态栈
    SqStack2 *sqStack2 = new SqStack2;
    // TODO:这里要更改使用策略  如果使用数组确实方便 但是对于属性等的计算统计不如vector
    sqStack2->base = new int[100];
    push2(sqStack2,7);

    cout<<"the length is :" << sqStack2->top<<endl;



}

int main()
{
    ClientCode();


    return 0;


}