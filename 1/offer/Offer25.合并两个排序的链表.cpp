// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

// 方法一
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    int len1 = 0, len2 = 0;
    vector<int> nums;
    ListNode* l = new ListNode(0);
    while(l1 != nullptr){
        // len1++;
        nums.push_back(l1->val);
        l1 = l1->next;       
    }
    while(l2 != nullptr){
        // len2++;
        nums.push_back(l2->val);
        l2 = l2->next;
        
    }
    sort(nums.begin(), nums.end());
    ListNode* pre_node = l;
    for(auto& num:nums){
        printf("num = %d\n", num);
        ListNode* node = new ListNode(num);
        pre_node->next = node;
        // l->next = node;
        pre_node = pre_node->next;
    }
    return l->next;
}

// 方法二
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;  
        }
        else{
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }
    if(l1 == nullptr) cur->next = l2;
    if(l2 == nullptr) cur->next = l1;
    return head->next;
}

// 方法三
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    // ListNode* cur = head;
    if(!l1 && !l2) return nullptr;
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val < l2->val){
        // head = new ListNode(l1->val);
        head = l1;
        head->next = mergeTwoLists(l1->next, l2);
    }
    else{
        // head = new ListNode(l2->val);
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }
    return head;
}

int main(){
    ListNode *node_1 = new ListNode(1);
    ListNode *node_2 = new ListNode(2);
    ListNode *node_3 = new ListNode(4);
    
    node_1->next = node_2;
    node_2->next = node_3;

    ListNode *node2_1 = new ListNode(1);
    ListNode *node2_2 = new ListNode(3);
    ListNode *node2_3 = new ListNode(5);
    
    node2_1->next = node2_2;
    node2_2->next = node2_3;

    ListNode* l = mergeTwoLists(node_1, node2_1);
}