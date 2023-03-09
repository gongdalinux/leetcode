
ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* cur = reverseList(head->next);
    ListNode* tmp = cur->next;
    cur->next = tmp;

}

ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while(cur != nullptr){
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}