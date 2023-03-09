// 输入两个链表，找出它们的第一个公共节点。

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     while(headA != nullptr){
         ListNode *node_b = headB;
         while(node_b != nullptr){
              if(node_b == headA) {
                   return node_b;
              }
              node_b = node_b->next;
         }
         headA = headA->next;
     }       
     return nullptr;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
    }

作者：z1m
链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/shuang-zhi-zhen-fa-lang-man-xiang-yu-by-ml-zimingm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。