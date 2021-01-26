#include <iostream>
#include <algorithm>
#include <vector>
#include "listNode.h"

using namespace std;
typedef singleListNodeStru ListNode;
/* -------------------------------------------
 * 熟练掌握链表头插法
 * 熟练掌握删除列表结点
 * vector 相关使用方法以及reverse排序
 * ------------------------------------------*/

//struct ListNode {
//    int val;
//    ListNode *next;
////    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
//};

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

ListNode* partition(ListNode* head,int target)
{
    // 输入: head->1->2->3->4->5->NULL,
    // 特殊情况判断
    if (!head || !head->next) return head;

    ListNode* slow;
    ListNode* fast;
    vector<int> smallNumber;
    slow = head;
    fast = head->next;
    while(fast)
    {
        // 先顺序遍历 把小的数添加到vector中
        // 并且删除head中原来的小结点
        if(fast->val < target) {
            smallNumber.push_back(fast->val);
            slow->next = fast->next;
        }
        else
            slow = slow->next;
        fast = fast->next;
    }
    // 小技巧 将vector翻转
    reverse(smallNumber.begin(),smallNumber.end());

    // 头插法插入结点
    ListNode* s;
    for(int i = 0;i < smallNumber.size();i++)
    {
        s = new ListNode;
        s->val = smallNumber[i];

        s->next = head ->next;
        head -> next = s;
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    int target = 3;

    partition(head,target);

    return 0;
}