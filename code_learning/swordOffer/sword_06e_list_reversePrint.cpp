#include <iostream>
//#include "listNode.h"
#include <vector>
#include <algorithm>

using namespace std;

/* -------------------------------------------
 * 链表的应用 ac 50 66
 * 逆向打印链表可以先正序再reverse
 * ------------------------------------------*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

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

vector<int> reversePrint(ListNode* head) {
    vector<int>result;
    if(!head) return result;
    while(head->next)
    {
        result.push_back(head->val);
        head = head->next;
    }
    result.push_back(head->val);
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    ListNode *l1 = new ListNode;
    initList(l1);

    reversePrint(l1);

    return 0;
}
