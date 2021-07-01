#include <iostream>
#include <algorithm>
#include <vector>
#include "listNode.h"

using namespace std;
typedef singleListNodeStru ListNode;
/* -------------------------------------------
 * 0 - 递归方式不太好懂 时间复杂度相对高一点 先不看
 * 1 - 迭代的方式用起来习惯一点 额外加入了将剩余部分也翻转
 * 注意：
 * 先统计总长度
 * 创建哨兵 且保持在K这一区间的前面
 * ------------------------------------------*/
ListNode* initList(ListNode *Head)
{
    Head->val = 0;
    Head->next = nullptr;
    ListNode *s;
    vector<int> array = {1,4,3,2,5,2};
    reverse(array.begin(),array.end());
    // 头插法进行链表填充
    for(int i = 0; i < 6; i++)
    {
        // 需要进行如下操作 否则报段错误
        s = new ListNode;
        s->val = array[i];
        // 开始插入
        s->next = Head->next;
        Head->next = s;
    }
    return Head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy(0), *pre = dummy, *next, *cur = pre;
    pre->next = head;
    int len = 0;
    while (cur = cur->next) ++len; // 计算链表节点个数（长度）
    // TODO：最精髓三指针调整部分
    while (len >= k) { // pre->..->cur->next
        cur = pre->next;
        next = cur->next;
        for (int i = 1; i < k; ++i) { // 处理 “车箱”
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = cur->next;
        }
        pre = cur, len -= k; // 处理下节 “车箱”
    }
    // TODO:面试部分--如果需要将剩余的再进行翻转 1就不用操作了
    if(len>1)
    {
        cur = pre->next;
        next = cur->next;
        while(next)
        {
            cur = next->next;
            next->next = cur;
            pre->next = next;
            next = cur->next;
        }
    }

    return dummy->next; // 返回第一节车箱的车头
}

int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    reverseList(head);
    return 0;
}