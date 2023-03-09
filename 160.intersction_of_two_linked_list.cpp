#include<iostream>
#include<map>
#include<unordered_map>

// 相交链表

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
};

// 双指针法 len(A) + len(B) = len(B) + len(A) 所以在共同节点相交
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if(!headA || !headB) return NULL;
    ListNode *pA = headA, *pB = headB;
    while(pA != pB){
        pA = pA==NULL ? headB : pA->next;
        pB = pB==NULL ? headA : pB->next;
    }
    return pA;
}

// 哈希表法
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    unordered_map<ListNode*, int> map;
    if(!headA || !headB) return NULL;
    while(headA != NULL){
        map[headA]++;
        headA = headA->next;
    }
    while(headB != NULL){
        if(map[headB]) return headB;
        headB = headB->next;
    }
    return NULL;
}
