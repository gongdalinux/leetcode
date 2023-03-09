// 回文链表
#include<iostream>
#include<vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};

ListNode *revertList(ListNode* head);

bool isPalindrome(ListNode* head) {
    vector<int> vals;
    while(head != NULL){
        vals.push_back(head->val);
        head = head->next;
    }
    int len = vals.size() - 1;
    for(int i=0, j = len; i<j; i++, j--){
        if(vals[i] != vals[j]) return false;
    }
    return true;
}

// bool isPalindrome(ListNode* head) {
//     vector<int> vals;
//     while (head != nullptr) {
//         vals.emplace_back(head->val);
//         head = head->next;
//     }
//     for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
//         if (vals[i] != vals[j]) {
//             return false;
//         }
//     }
//     return true;
// }


int main(){
    ListNode *node_1 = new ListNode(1);
    ListNode *node_2 = new ListNode(2);
    ListNode *node_3 = new ListNode(1);
    
    node_1->next = node_2;
    node_2->next = node_3;
    bool flag = isPalindrome(node_1);
    printf("flag = %d", flag);
}