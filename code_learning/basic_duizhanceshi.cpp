#include <iostream>
#include "../heads/listNode.h"
using namespace std; 

/*---TODO(Lordon):本次实验验证 函数栈之间的存储情况
 *ClientCode 与 creatSingleList 之间都有各自的函数栈 他们new出来的都存储在堆中 指针与变量存在他们的函数栈内
 *1、此处如果在原来的指针上new一个对象那么原来当前节点地址会被替换掉 next所指不变
 *2、如果delete当前头结点那么堆栈会清除，此头结点可继续new新接点
 *
 * ---*/


singleListNode creatSingleList(singleListNode* newlist, int value)
{
    cout<<"before new pointer address is: "<<newlist<<endl;
    cout<<"before new pointer data is: "<<newlist->data<<endl<<endl;
     newlist = new singleListNode;
     newlist->data = value; // 直接覆盖传进来的newlist头指针 next不变 意思就是两个地址都指向同一个list内容

    cout<<"after new pointer address is: "<<newlist<<endl;
    cout<<"after new pointer data is: "<<newlist->data<<endl;

    delete newlist;// 更改当前节点？？ 怎么回事 还是存在list
}

singleListNode* creatSingleListAndReturn(singleListNode* newlist, int value)
{
    cout<<"before new pointer address is: "<<newlist<<endl;
    cout<<"before new pointer data is: "<<newlist->data<<endl<<endl;
    newlist = new singleListNode;
    newlist->data = value;

    cout<<"after new pointer address is: "<<newlist;
    cout<<"after new pointer data is: "<<newlist->data<<endl;
    return newlist;
}
singleListNode changeSingleList(singleListNode* newlist, int value)
{
    cout<<"before new pointer address is: "<<newlist<<endl;
    cout<<"before new pointer data is: "<<newlist->data<<endl<<endl;
    newlist->data = value  ;

    cout<<"after new pointer address is: "<<newlist<<endl;
    cout<<"after new pointer data is: "<<newlist->data<<endl;

}

void ClientCode()
{
    singleListNode *test= new singleListNode;
    test->data = 1;

    cout<<"struct address is: "<<test<<endl;
    cout<<"struct data is: "<<test->data<<endl;

    // 测试同一地址new 并delete
    creatSingleList(test,2) ;

    cout<<"struct address is: "<<test<<endl<<
    " and the data is:"<<test->data<<endl<<"so ceratSingleList function will not change it"<<endl<<endl;

    // 同一地址new然后返回地址 覆盖原来list头指针
    test = creatSingleListAndReturn(test,3);

    cout<<"get new address from function is: "<<test<<endl<<
    " and the data is:"<<test->data<<endl<<"the second function has changed it ";

    // 引用传递 同步变化
    changeSingleList(test,4);

    cout<<"get new address from function is: "<<test<<endl<<
        " and the data is:"<<test->data<<endl<<"the second function has changed it ";
}

int main()
{
    ClientCode();
    return 0;

}