#include<iostream>

typedef struct ListNode{
    int val;
    ListNode *next;
};

ListNode* reverseList(ListNode* head){
    ListNode *pre = NULL;
    ListNode *cur = head;
    ListNode *temp;
    while(cur != NULL){
        temp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = temp;
    }
    return pre;
}

// 递归法
ListNode* reverseList(ListNode* head){
    if((head == NULL) || (head->next == NULL)) return head;
    ListNode* node = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
} 

int main(){

}