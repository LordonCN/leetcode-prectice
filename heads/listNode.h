#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

/* -------------------------------------------
 * 静态顺序存储
 * -------------------------------------------*/
struct staticList
{
    int dataArray[100]{};
    int length = 0;
};

/* -------------------------------------------
 * 动态数组创建
 * dynamicSequenceList dynaList;
 * dynaList.element = new int[100];
 * -------------------------------------------*/
struct dynamicSequenceList{
    int* element; // 此处需要申请分配存储空间
    int length = 0;
};

/* -------------------------------------------
 * 单链表创建 带构造函数的单链表
 * -------------------------------------------*/
struct singleListNode{
    int data;
    singleListNode *next;
};

struct singleListNodeStru{
    int data;
    singleListNodeStru*next;
    singleListNodeStru() : data(0), next(nullptr) {} // 无参数传入的构造函数
};

/* -------------------------------------------
 * 双向链表
 * -------------------------------------------*/
struct doubleListNode
{
    int data;
    doubleListNode *prior,*next;
};

class State {
  /**
   * @var Context
   */
private:
    float numberReally;
    
protected:
    int numberTest;

public:
    virtual ~State() {};
    void set_context() {this->numberTest = 1;};
    void set_floatnumber(){this->numberReally = 4;};

    virtual void Handle1() = 0;
};



#endif