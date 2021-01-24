#include <iostream>
#include "listNode.h"
using namespace std; 
/*结构体初始化的时候用*跟不用到底有什么区别? */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

int main()
{
   ListNode* l1, l2;
   // 便于返回新链表,l1，l2结点追加到新链表中
   ListNode *newHead;
   ListNode *pi = &newHead;
   // 空有两种情况 l1将链表遍历到空或者l2本身为空
   while(l1 && l2)
   {
       // 小的数都给l1
       if(l1->val > l2->val) swap(l1, l2);
       // 追加
       pi->next = l1;
       l1 = l1->next;
       pi = pi->next;
   }
   // 将最后剩余的都加进去
   pi->next = l1 ? l1 : l2;

//   return newHead.next;

    return 0;
}