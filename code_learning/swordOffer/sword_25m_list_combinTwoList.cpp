#include <iostream>
//#include "listNode.h"
using namespace std;

/* -------------------------------------------
 * 链表的应用
 * swap的常见用法 可以交换链表 vector 多种类型数据模板
 * 不仅可以整体交换还能对vector指定位置进行操作
 * ------------------------------------------*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

ListNode* initList(ListNode *&Head)
{
    Head->val = 0;
    Head->next = nullptr;
    ListNode *s;
    // 头插法进行链表填充
    for(int i = 5; i > 0; i--)
    {
        // 需要进行如下操作 否则报段错误
        s = new ListNode;
        s->val = i;
        // 开始插入
        s->next = Head->next;
        Head->next = s;
    }
    return Head;
}

ListNode* combinTwoList(ListNode* &l1,ListNode* &l2)
{
    ListNode *s,*result;
    result = new ListNode;
    s = new ListNode;
    result->next = s;
    while(l1 && l2)
    {
        if(l1->val > l2->val)swap(l1,l2);
        // 添加 l1->val 到s
        s ->next = l1;
        l1 = l1->next;
        s = s->next;
    }
    s->next = l1?l1:l2;
    return result->next->next;
}

int main()
{
    ListNode *l1,*l2;
    initList(l1);
    initList(l2);
    combinTwoList(l2,l2);
    return 0;
}
