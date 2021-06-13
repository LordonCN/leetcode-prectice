#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std; 
/* -------------------------------------------
 * 熟练掌握链表头插法 以及掌握链表深度的搜索方式(比如找最后一项)
 * ------------------------------------------*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 无参数传入的构造函数
};


// init 1->2->3->4->5->null
ListNode* initList(ListNode *Head)
{
    Head->val = 5;
    Head->next = nullptr;
    ListNode *s;
    // 头插法进行链表填充
    for(int i = 4; i > 0; i--)
    {
        // 需要进行如下操作 否则报段错误
        s = new ListNode;
        s->val = i;
        // 开始插入
        s->next = Head;
        Head = s;
    }
    return Head;
}

// 0->1->2->3->..->8->null
ListNode* initList2(ListNode *Head)
{
    Head->val = 0;
    Head->next = nullptr;
    ListNode *s;
    for(int i = 8; i > 0; i--)
    {
        s = new ListNode;
        s->val = i;
        // 开始插入
        s->next = Head->next;
        Head->next = s;
    }
    return Head;
}

void addTwoNumbers1(ListNode* &list1,ListNode* &list2)
{
    ListNode* headPoint = new ListNode;
    ListNode* s;
    headPoint->next = list1;
    while(list1||list2)
    {
        // 倒数第二个之前以及l2长的时候最后一个
        if((list2->next && list1->next)||(!list1->next && !list2->next))
        {
            list1->val += list2->val;// 进位没考虑？
            list1 = list1->next;
            list2 = list2->next;
        }
        // list1为最后一个 list2还没到最后一个
        else if(list2->next && !list1->next)
        {
            s = new ListNode;
            list1->next = s;
            list1->val += list2->val;
            list1 = list1->next;
            list2 = list2->next;
        }
        // l1长的时候
        else
        {
            list1-> val += list2->val;
            break;
        }
    }
    // 得到长的list1

    // 将链表元素保存到map中
    int howmany = 0;
    unordered_map<int,int> numbsermap;
    headPoint = headPoint->next;

    // 这里将链表读取到map中即变成了正序 for(auto number : numbermap)
    // for循环头插即可完成数值颠倒 61题为头插 这里我们用尾插法
    while(headPoint)
    {
        numbsermap[howmany] = headPoint->val;
        howmany ++;
        headPoint = headPoint->next;
    }

    // 还是用headPoint
    headPoint  = new ListNode;
    ListNode* output = new ListNode;
    output->next = headPoint;
    for(auto number : numbsermap)
    {
        s = new ListNode;
        s->val = number.second;
        headPoint->next = s;
        headPoint = headPoint->next;
    }

    // result is :output->next->next;
}


/* -------------------------------------------
 * ac 31.72 96
 * 思路：
 * 将list1 与 list2相加 先连成一个list1
 * 再通过遍历list1 完成进位操作
 * ------------------------------------------*/
ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
    // 整一个哨兵
    ListNode *solder = new ListNode;
    solder->next = list1;

    while(list1->next && list2)
    {
        list1->val += list2->val;
        list1 = list1->next;
        list2 = list2->next;
    }
    if(list1->next && !list2)// list2空了 只处理list1即可
    {
        goto outputdeal;
    }
    if(!list1->next && list2)// 将list1接到list2上 处理list1
    {
        list1->val += list2->val;
        list1->next = list2->next;
        goto outputdeal;
    }
    outputdeal:// come here
    list1 = solder->next;
    int addMe = 0;
    for(int i = 0;list1;i++)
    {
        if(list1->val>=10)
        {
            int a = list1->val%10;// 取出来末位
            int inc = list1->val/10;// 取首位
            int b = (a + addMe)%10;// 个位加进位
            addMe = inc + (a + addMe)/10;// 若还有进位
            list1->val = b;
        }
        else
        {
            int b = (list1->val + addMe)%10;// 个位加进位
            addMe = (list1->val + addMe)/10;// 若还有进位
            list1->val = b;
        }

        if(!list1->next)// 要结束了 但是还有进位
            if(addMe)
            {
                ListNode* s = new ListNode;
                s->val = addMe;
                list1->next = s;
                break;
            }
        list1 = list1->next;
    }
    return solder->next;
}

int main()
{
    ListNode *head = new ListNode;
    ListNode *head2= new ListNode;
    head= initList(head);
    head2= initList2(head2);

    addTwoNumbers(head,head2);

    return 0;
}