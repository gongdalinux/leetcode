// 二叉树的最小深度

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

int minDepth(TreeNode* root){
    if(root == nullptr) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if(l == 0) return r + 1;
    else if(r == 0) return l+1;
    else return min(l, r) + 1;
}