#include<iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

ListNode* deleteNode(ListNode* head, int val) {
    ListNode* pre = nullptr;
    if(head->val == val) return head->next;
    ListNode* cur = head;
    // for(auto cur = head; cur != nullptr; cur = cur->next){
    while(cur != nullptr){
        if(cur->val == val){
            pre->next = cur->next;
        }
        pre = cur;
        cur = cur->next;
    }
    return head;
}

void printNode(ListNode* node){
    while(node != nullptr){
        printf("val = %d\n", node->val);
        node = node->next;
    }
}

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = nullptr;
    printNode(node_1);
    printf("List\n");
    ListNode* new_list = deleteNode(node_1, 2);
    printNode(new_list);
}