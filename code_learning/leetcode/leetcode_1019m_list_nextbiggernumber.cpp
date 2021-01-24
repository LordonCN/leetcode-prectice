#include <iostream>
#include "listNode.h"
#include <vector>
using namespace std;

/* -------------------------------------------
 * 快慢指针比较大小
 * 链表作为停止条件时 fast==NULL 遍历到倒数第一个head->next != nullptr
 * ------------------------------------------*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

ListNode* initList(ListNode* Head)
{
    Head->val = 0;
    Head->next = nullptr;
    ListNode *s;
    // 头插法进行链表填充
    for(int i = 2; i > 0; i--)
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

vector<int> findBiggerNumber(vector<int>&result,ListNode* head)
{
    // special judge
    if(!head->next) return vector<int>{0};
    ListNode* fast;
    fast = head->next;
    bool nochange = true;

    // 遍历到倒数第1个
    while(head->next != nullptr)
    {
        while(fast!=NULL)
        {
            //  后面的数变小了
            if(head->val>=fast->val){
                if(nochange) {
                    head->val = 0;
                }
                result.push_back(head->val);
                break;
            }
            else{
                head->val = fast->val;
                nochange  = false;
                fast = fast->next;
            }
        }
        if(nochange) {
            head->val = 0;
        }
        result.push_back(head->val);
        // 寻找下一个数字的最大值
        head = head->next;
        fast = head->next;
        nochange = true;
    }
    // 最后一个一定是0
    result.push_back(0);


    return result;
}

int main()
{
   ListNode* head;
   initList(head);

   vector<int> result;

   result = findBiggerNumber(result,head);


   return 0;
}