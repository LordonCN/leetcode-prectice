#include <iostream>
#include <string>
#include <stack> 

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
    ListNode *list;
    list = new ListNode;

    int n = 10;// 删除倒数第10个元素 所以快指针要先多走n步 然后同步运动直到快指针到末尾

    // 特殊情况
    if(!list->next) return 0;

    ListNode *fast,*slow;
    fast = slow = list;// 都指向起始位置
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
    // 之前跳过的那个节点要删除不 ？ 是应该删除 但是这里程序结束也释放掉了 无所谓
    //
    delete slow,fast;

    return 0;
}



