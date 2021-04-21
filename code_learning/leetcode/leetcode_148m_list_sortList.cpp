#include <iostream>
#include <algorithm>
#include <vector>
#include "listNode.h"

using namespace std;
typedef singleListNodeStru ListNode;
/* -------------------------------------------
 * 熟练掌握链表遍历的方法
 * ac 98 10 因为使用了快排 时间复杂度最低 使用vector存储空间复杂度高了
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
ListNode* insertionSortList(ListNode* head) {
    ListNode * solder = new ListNode;
    solder->next = head;
    vector<int>bucket;
    while(head)
    {
        bucket.push_back(head->val);
        head = head->next;
    }
    head = solder->next;
    sort(bucket.begin(),bucket.end());
    for(int i = 0 ;i < bucket.size();i++)
    {
        head->val = bucket[i];
        head = head->next;
    }
    return solder->next;
}

int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    int target = 3;

    insertionSortList(head);

    return 0;
}