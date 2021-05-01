#include <iostream>
#include "listNode.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

/*需要三个指针相互合作才能交换完成*/
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);//哨兵
    ListNode* pre = dummy;
    ListNode* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        ListNode* t = cur->next;
        cur->next = t->next;
        t->next = cur;
        pre->next = t;
        pre = cur;
        cur = pre->next;
    }
    return dummy->next;
}

int main()
{
    ListNode *Head;
    // 特殊情况判断
    if (!Head)
        return 0;
    // 创建守卫用来返回结果  创建前置指针用来连接
    ListNode *Pre = new ListNode,*follow;
    Pre->next = Head;
    follow = Pre;

    // 如果可以交换 不是奇数
    while (Head->next)
    {
        ListNode *s = Head->next;
        // 前到后
        Head->next = s->next;
        // 后到前
        s->next = Head;
        // 头连接
        follow->next = s;

        // 为下一轮做准备
        follow = Head;
        Head = Head->next;
    }

//    return Pre->next;

    return 0;

}