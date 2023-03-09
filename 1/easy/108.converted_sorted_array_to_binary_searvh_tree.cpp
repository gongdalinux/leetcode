// 将有序数组转换成二叉树

// [-10,-3,0,5,9]

#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
public:
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
    if(start >= end){
        return nullptr; 
    }
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, start, mid);
    root->right = helper(nums, mid+1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    TreeNode* node = helper(nums, 0, n);
    return node;
}



