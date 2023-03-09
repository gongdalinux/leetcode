// 二叉树最大路径和
#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

int max_val = INT_MIN;

int maxPathSum(TreeNode* root) {
    postOrder(root);
    return max_val;
}

int postOrder(TreeNode* root){
    if(root == NULL) return 0;

    //计算左边分支最大值，左边分支如果为负数还不如不选择
    int l = max(postOrder(root->left), 0);
    //计算右边分支最大值，右边分支如果为负数还不如不选择
    int r = max(postOrder(root->right), 0);
    // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
    int max_path = root->val + l + r;
    max_val = max(max_val, max_path);

    // 返回经过root的单边最大分支给当前root的父节点计算使用
    return root->val + max(l, r);
}