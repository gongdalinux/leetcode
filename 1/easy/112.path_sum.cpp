// 路径总和

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

bool sum_result(TreeNode* root, int targetSum, int sum){
    if(root == nullptr) return false;
    sum += root->val;
    if((root->left == nullptr) && (root->right == nullptr)){
        return sum == targetSum;
    }
    bool l = sum_result(root->left, targetSum, sum);
    bool r = sum_result(root->right, targetSum, sum);
    
    return l || r;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    return sum_result(root, targetSum, sum);
}