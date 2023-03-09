#include<iostream>

using namespace std;

typedef struct ListNode
{
    int val; 
    ListNode *next;
};

ListNode *reverse_list(ListNode *head){
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

ListNode *reverse_list(ListNode *head){
    if((head == NULL) || (head->next == NULL)) return head;
    ListNode* node = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL) { return NULL; }
    ListNode* cur = head;
    while (head->next != NULL) {
        ListNode* t = head->next->next;
        head->next->next = cur;
        cur = head->next;
        head->next = t;
    }
    return cur;
}

作者：huwt
链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-shuang-zhi-zhen-di-gui-yao-mo-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。