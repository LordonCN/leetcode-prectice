#include <iostream>
#include "listNode.h"
#include <unordered_map>

using namespace std; 
/* -------------------------------------------
 * 熟练掌握链表头插法 以及掌握链表深度的搜索方式(比如找最后一项)
 * ------------------------------------------*/

struct ListNode {
    int val;
    ListNode *next;
//    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};

ListNode* initList(ListNode *Head)
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

ListNode* rotateRightLastToFront(ListNode* head,int target)
{
    // 输入: head->1->2->3->4->5->NULL,
    // 特殊情况判断
    if (!head || !head->next) return head;
    // 统计链表总长度
    ListNode* sum  = head;
    ListNode* s ;
    int length = 0;
    while(sum->next)
    {
        sum = sum->next;
        length++;
    }
    while(target--)
    {
        s = new ListNode;
        s = head;
        // 先将倒数第二个next->null
        for(int i = 1;i< length;i++)
            s = s->next;
        // 保存最后一个
        sum = s->next;
        // 置空
        s->next = sum->next;
        sum->next = head->next;
        head->next = sum;
    }
    return head;
}

void rotateRightMap(ListNode* head,unordered_map<int,int>numberSum)
{
    ListNode* sum = head;
    int howmany = 0;
    // 将链表元素保存到map中
    while(sum)
    {
        numberSum[howmany] = sum->val;
        howmany ++;
        sum = sum->next;
    }
    // 1.可以直接对for(auto A : numberSum)进行循环遍历 使用尾插法创建一个新的

    // 2.此处使用头插法进行顺次遍历
    ListNode* s;
    // 删除原head内容 头插法重新创建
    head->next = nullptr;
    for(int i = 1;i<howmany;i++)
    {
        s = new ListNode;
        s->val = numberSum[i];
        s->next = head;
        head = s;
    }

}
int main()
{
    ListNode *head = new ListNode;
    head = initList(head);
    int target = 2;

    // 暴力破解 遍历完后挨个挪到前面
//    rotateRightLastToFront(head,target);

    // map 哈希查表 这里没有int,int类型的map 所以再cpp中不适用
    // 1.26 反攻
    unordered_map<int,int> numberSum;
    rotateRightMap(head,numberSum);

    return 0;
}