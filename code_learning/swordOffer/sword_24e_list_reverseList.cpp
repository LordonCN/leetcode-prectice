#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 链表的应用 ac 68 27
 * 特殊情况 传入链表为空的时候
 * 思路：
 * 1 保存到vector然后头插法
 * 2 一边遍历一边头插
 * ------------------------------------------*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

// 0625 复习
ListNode* reverseList0625(ListNode* head) {
    // 方法1：遍历出来重新塞回去 用vector存储即可 2n
    // 方法2：先将head移动到最后 然后逐个插入 2n
    ListNode* solider = new ListNode;
    solider = head;
    while(head->next)
        head = head->next;
    while(solider != head)
    {
        ListNode* s = new ListNode;
        s->val = solider->val;
        s->next = head->next;
        head->next = s;
        solider = solider->next;
    }
    return head;
}



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

// 方法2：逐个向后添加
ListNode* reverseList(ListNode* head) {
    if(!head)return head;
    ListNode* temp,*s_;
    temp = new ListNode;
    temp = nullptr;
    while(head->next)
    {
        s_ = new ListNode;
        s_->val = head->val;
        head = head->next;
        s_->next = temp;
        temp = s_;
    }
    head->next = temp;
    return head;
}

int main()
{
    ListNode *l1 = new ListNode;
    initList(l1);

    reverseList(l1);

    return 0;
}
