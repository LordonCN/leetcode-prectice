#include <iostream>
#include <string>
#include <stack> // 本身就是一个模板类
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

/*************************************************************************
 * 快慢指针
 * 特殊情况： list->next = null
 * 易错点： 创建的链表即使delete
 *======================================================================*/
int main()
{
    ListNode *list; // 构造函数中已经有赋值跟指向空了
    int n = 10;

    // 特殊情况
    if(!list->next)
    {
        return 0;
    }

    ListNode *fast,*slow;
    fast = slow = list;
    // fast迁移n步
    while(n--)
    {
        fast = fast->next;
    }
    // fast and slow move together
    while(nullptr != fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // 慢指针删除结点
    slow->next = slow->next->next;
    // 之前跳过的那个节点要删除不 ？
    delete slow,fast;

    return 0;
}



