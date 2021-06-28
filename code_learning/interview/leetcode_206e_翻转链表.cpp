#include <iostream>
#include <algorithm>
#include <vector>
#include "listNode.h"

using namespace std;
typedef singleListNodeStru ListNode;
/* -------------------------------------------
 * 0、head始终指向前端 stone指向初始head保持不动 mov指向stone->next [目前最优]
 * 1、熟练掌握链表头插法 ac 51 85 [涉及三指针  2n时间]
 * 2、vector 相关使用方法以及reverse反转 [代码最多 时间2n 空间最大n]
 * 3、利用listnode性质进行循环创建 [代码最简洁]
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

// methord 0: 最优
ListNode* reverseList(ListNode* head) {

    if(!head || !head->next)return head;
    // stone 始终指向1
    ListNode* stone = head;
    ListNode* mov = stone->next;

    while(mov)
    {
        stone->next = mov->next;// 向后指 释放mov
        mov->next = head;// mov拿到前边来
        head = mov;// 更新头结点
        mov = stone->next;// 指向下一个要拿到前边来的结点
    }
    return head;
}

// methord 3;
ListNode* reverseList(ListNode* head) {
    ListNode* ans = nullptr;
    for(auto node = head;node !=nullptr;node = node->next)
        ans = new ListNode(node->val,ans);
    return ans;

}

// methord 2:
ListNode* reverseList(ListNode* head) {
    vector<int>vec;
    if(!head || !head->next)return head;
    ListNode* solider = head;
    while(head)
    {
        vec.push_back(head->val);
        head = head->next;
    }
    reverse(vec.begin(),vec.end());
    head = solider;
    for(int i = 0;i<vec.size();i++)
    {
        head->val = vec[i];
        head = head->next;
    }
    return solider;
}


int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    reverseList(head);
    return 0;
}