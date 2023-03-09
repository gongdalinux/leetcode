
// 给定一个链表: 1->2->3->4->5, 和 k = 2.

// 返回链表 4->5.

ListNode* getKthFromEnd(ListNode* head, int k) {
   int n = 0;
   ListNode *fast = head;
   ListNode *slow = head;
   while(fast != nullptr){
       n++;
       if(n>k) slow = slow->next;
       fast = fast->next;
   } 
   return slow;
}


ListNode* getKthFromEnd(ListNode* head, int k) {
   int n = 0;
   ListNode *fast = head;
   ListNode *slow = head;
   for(int i=0; i<k; i++){
       fast = fast->next;
   }
   while(fast != nullptr){
       fast = fast->next;
       slow = slow->next;
   }
   return slow;
}

ListNode* getKthFromEnd(ListNode* head, int k) {
    int n = 0;
    ListNode *p;
    for(p=head; p!=nullptr; p=p->next){
        n++;
    }
    k = k % n;
    if (k < 1) { return head; }
    k = n - k;
    p = head;
    while(k-- > 0)
        p = p->next;
    return p;
}