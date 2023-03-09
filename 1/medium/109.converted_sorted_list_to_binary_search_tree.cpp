// 将有序链表转换成二叉搜索树

#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    };
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    };
};

TreeNode* helper(vector<int>& nums, int start, int end){
    if(start >= end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, start, mid);
    root->right = helper(nums, mid+1, end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while(head != nullptr | head->next != nullptr){
        nums.push_back(head->val);
        head = head->next;
    }
    int n = nums.size();
    return helper(nums, 0, n);
}