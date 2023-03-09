// 环形链表
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
};

// 方法一
bool hasCycle(ListNode* list){
    unordered_map<ListNode*, int> map;
    while(list != NULL)
    {
        map[list]++;
        if(map[list] > 1) return true;
        list = list->next;
    }
    return false;
}

bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> seen;
    while (head != nullptr) {
        if (seen.count(head)) {
            return true;
        }
        seen.insert(head);
        head = head->next;
    }
    return false;
}

// 方法二 快慢指针 快指针每次走两步 慢指针走一步
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}