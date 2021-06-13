#include <iostream>
#include <algorithm>
#include <vector>
#include "listNode.h"

using namespace std;
typedef singleListNodeStru ListNode;
/* -------------------------------------------
 * ac 100 11
 * 熟练掌握链表头插法
 * 熟练掌握删除列表结点
 * 多个结点删除使用vector更加方便
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
    vector<int> array = {1,1,2,3,3,3,4,5,6,6,7};
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

ListNode* deleteDuplicates(ListNode* head) {
    ListNode*solder = new ListNode;
    if(!head || !head->next)return head;
    solder->next = head;
    vector<int>nums;
    bool sign = false;// 加标志位判断是否有重复的出现
    while(head){
        
        if(nums.empty())
            nums.push_back(head->val);
        else if(head->val == nums.back()){
            sign = true;
        }
        else{
            if(sign)
                nums.pop_back();// 一直到最后才pop出去
            nums.push_back(head->val);
            sign = false;
        }
        head = head->next;
    }
    if(sign)nums.pop_back();
    
    ListNode *solder2 = new ListNode;
    ListNode *s;
    head = new ListNode;
    solder2->next = head;
    for(int i = 0;i<nums.size();i++)
    {
        s = new ListNode;
        s->val = nums[i];
        head->next = s;
        head = head->next;
    }
    return solder2->next->next;
}

int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    deleteDuplicates(head);
    return 0;
}