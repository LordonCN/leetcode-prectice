#include <iostream>
#include "listNode.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

int main()
{
    ListNode *Head;
    // 特殊情况判断
    if (!Head)
        return 0;
    // 创建守卫用来返回结果  创建前置指针用来连接
    ListNode *Pre,*follow;
    Pre->next = Head->next;
    follow = Pre;

    // 如果可以交换 不是奇数
    while (Head->next)
    {
        ListNode *s = Head->next;
        // 开始交换
        Head->next = s->next;
        s->next = Head;
        follow->next = s;

        // 为下一轮做准备
        follow = Head;
        Head = Head->next;
    }

//    return Pre->next;

    return 0;

}