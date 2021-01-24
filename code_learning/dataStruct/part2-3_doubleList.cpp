#include <iostream>
#include "listNode.h"
using namespace std; 
/*结构体初始化的时候用*跟不用到底有什么区别? */

bool initSingleList(singleListNode *list) //这里不能取地址
{
    // list = new singleListNode;
    
    cout<<"the address in function is : "<<list<<endl;
    if(!list)
    {
        return false;
    }
    // 当前数据域
    list->data = 10;
    // 头结点的指针域  置空
    list->next = nullptr;

    return true;
}

singleListNode* creatSingleList(singleListNode* newlist, int value)
{
    // singleListNode *newlist;
    newlist->data = value;
    newlist->next = nullptr;

    return newlist;
}

// 头插法 原理如下 
/*list->0   s->?
 list->s->0
 list->s1->s->0 */
void headInsertList(singleListNode *list)
{
    cout<<"please input how many numbers you want to insert:"<<endl;
    int inseartNumber = 0;
    cin>>inseartNumber;

    singleListNode *s;
    while(inseartNumber--)
    {
        int data;
        s = new singleListNode;
        cout<<"*****************************************"<< endl;
        cout<<"list address : "<<list<< endl;
        cout<<"list->next address : "<<list->next<< endl;
        cout<<"s address is: "<<s<< endl;
        cout<<"s->next address is: "<<s->next<< endl;
        cout<<"*****************************************"<< endl;

        cout<<"please input insert data:"<<endl;
        cin>>s->data;
        s->next = list->next;

        list->next = s;
        cout<<"*****************************************"<< endl;
        cout<<"list address : "<<list<< endl;
        cout<<"list->next address : "<<list->next<< endl;
        cout<<"s address is: "<<s<< endl;
        cout<<"s->next address is: "<<s->next<< endl;
        cout<<"*****************************************"<< endl;
  }
}

// 尾插法
void tailInsertList(singleListNode *list)
{
    cout<<"please input how many numbers you want to insert:"<<endl;
    int inseartNumber = 0;
    cin>>inseartNumber;

    // 首先将尾指针指过去
    singleListNode *tail,*s ;
    cout<<tail->next<<endl;
    tail = list;

    while(inseartNumber--)
    {
        int data;
        s = new singleListNode;
        cout<<"+++++++++++++++++init state++++++++++++++++++++++"<<endl;
        cout<<"list address : "<<list<< endl;
        cout<<"list->next address : "<<list->next<< endl;
        cout<<"tail address is: "<<tail<< endl;
        cout<<"tail->next address is: "<<tail->next<< endl;
        cout<<"s address is: "<<s<< endl;
        cout<<"s->next address is: "<<s->next<< endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++"<<endl;

        cout<<"please input insert data:"<<endl;
        cin>>s->data;
        // tail and list change together
        tail->next = s;
        cout<<"--------------tail point to s head------------"<<endl;
        cout<<"list address : "<<list<< endl;
        cout<<"list->next address : "<<list->next<< endl;
        cout<<"tail address is: "<<tail<< endl;
        cout<<"tail->next address is: "<<tail->next<< endl;
        cout<<"s address is: "<<s<< endl;
        cout<<"s->next address is: "<<s->next<< endl;
        cout<<"------------------------------------------"<<endl;
        // list->next指向了s head  tail=s
        tail = s ;
        cout<<"*****************************************"<<endl;
        cout<<"list address : "<<list<< endl;
        cout<<"list->next address : "<<list->next<< endl;
        cout<<"tail address is: "<<tail<< endl;
        cout<<"tail->next address is: "<<tail->next<< endl;
        cout<<"s address is: "<<s<< endl;
        cout<<"s->next address is: "<<s->next<< endl;
        cout<<"*****************************************"<< endl;
  }
}

void initDoubleList(doubleListNode &L)
{
    L.data = 10;
    cout<<"the data is: "<<L.data<< endl;
    L.prior = nullptr;
    L.next = nullptr;
    cout<<"the address is: "<<L.prior<<" "<<L.next<< endl;
}

void initDoubleListPointer(doubleListNode *L)
{
    L->data = 10;
    L->prior = nullptr;
    L->next = nullptr;
}

void ClientCode()
{
    doubleListNode doubleList;
    initDoubleList(doubleList);



    // headinsert test
    // headInsertList(&list_single);



}

int main()
{
    ClientCode();


    //stop for a while
    int stopForAwhile;
    cout<<endl;
    cout<<"To stop the terminal close auto, add this to stop it";
    cin>>stopForAwhile;

    return 0;


}