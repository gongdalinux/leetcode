// 从尾到头打印链表
// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

// 方法一：递归
vector<int> res;

void dfs(ListNode* head){
    if(head == nullptr) return;
    dfs(head->next);
    res.push_back(head->val);
}

vector<int> reversePrint(ListNode* head) {
    dfs(head);
    return res;
}

// 方法二

vector<int> reversePrint(ListNode* head) {
    while(head != nullptr){
        res.insert(res.begin(), head->val);
        head = head->next;
    }
    return res;
}
