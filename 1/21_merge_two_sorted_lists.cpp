#include<iostream>

typedef struct ListNode
{
    int val;
    ListNode* next;
};

// 迭代法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *cur = new ListNode(-1);
    ListNode *pre = cur;
    while((l1 != NULL) && (l2 != NULL))
    {
        if(l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else 
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if (l1 == NULL) cur->next = l2;
    if (l2 == NULL) cur->next = l1;

    // cur->next = l1 == NULL ? l2 : l1; 
    return pre->next;
}

// 递归法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}