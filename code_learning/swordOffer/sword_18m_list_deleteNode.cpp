#include <iostream>
#include "listNode.h"
#include <unordered_map>

using namespace std;
/* -------------------------------------------
 * 熟练掌握链表头插法 以及掌握链表深度的搜索方式(比如找最后一项)
 * ------------------------------------------*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

ListNode* initList(ListNode *Head)
{
    Head->val = 0;
    Head->next = nullptr;
    ListNode *s;
    // 头插法进行链表填充
    for(int i = 3; i > 0; i--)
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

ListNode* deleteNode(ListNode* head,int target)
{
    ListNode* temp = new ListNode;
    temp->next = head;
    ListNode* s;
    while(head->next->next)// 保证至少长度为3 删除
    {
        if(head->next->val == target)//中间
        {
            s = new ListNode;
            s = head->next;
            head->next = s->next;
            s->next = nullptr;
            break;
        }
        else if(head->next->next->val == target && !head->next->next->next)//最后一个
        {
            head->next->next = nullptr;
            break;
        }
        head = head->next;
    }
    if(temp->next->val == target)// 第一个
        temp->next = temp->next->next;

    return temp->next;
}

int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    int target = 3;

    deleteNode(head,target);

    return 0;
}
