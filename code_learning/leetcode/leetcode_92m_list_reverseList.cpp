#include <iostream>
#include <algorithm>
#include <vector>
#include "listNode.h"

using namespace std;
typedef singleListNodeStru ListNode;
/* -------------------------------------------
 * 熟练掌握链表头插法 ac 51 85
 * 熟练掌握删除列表结点
 * vector 相关使用方法以及reverse反转
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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode*solder = new ListNode;
    solder->next = head;
    vector<int>result;
    while(head)
    {
        result.push_back(head->val);
        head = head->next;
    }
    reverse(result.begin()+left-1,result.begin()+right);

    head = new ListNode;
    head->next = solder->next;
    head = head->next;
    int i = 0;
    while(i<result.size())
    {
        head->val = result[i++];
        head = head->next;
    }
    return solder->next;
}

int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    reverseBetween(head);
    return 0;
}