#include <iostream>
#include "listNode.h"
#include <unordered_map>

using namespace std; 
/* -------------------------------------------
 * 环形链表 快慢指针移动
 * 不过我写的到底哪里错了 一直不通 反正就就是这么判断就行了
 * ------------------------------------------*/

struct ListNode {
    int val;
    ListNode *next;
//    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

ListNode* initList(ListNode *Head)
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

// 怎么这个就跑不通 ？？？？？ 我都服了
// bool hasCycle(ListNode *head) {
//     ListNode* q = head;
//     ListNode* s = head;

//     while(q->next != NULL && q != NULL)
//     {
//         q = q->next->next;
//         s = s->next;
//         if (s == q)
//             return true;
//     }
//     return false;
// }

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    hasCycle(head);

    return 0;
}