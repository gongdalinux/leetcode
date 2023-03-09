// 二叉树的直径
// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

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

int res = 0;

int depth(TreeNode *root){
    if(root == nullptr) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    res = max(res, left+right+1);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    res = 1;
    depth(root);
    return res - 1;
}