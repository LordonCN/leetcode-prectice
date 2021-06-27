class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head)return head;
        ListNode* solider = new ListNode;
        solider = head;
        while(k--)
            head = head->next;
        while(head)
        {
            head = head->next;
            solider = solider->next;
        }
        return solider;


    }
};作容易产生迭代器的错位 循环操作不建议使用