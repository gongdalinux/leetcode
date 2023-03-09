// 最长同值路径
// 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

#include<iostream>
#include<vector>
#include<map>
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

int longestUnivaluePath(TreeNode *root)
{
    if (!root)
        return 0;
    longestPath(root);
    return res;
}

int longestPath(TreeNode *root)
{
    if (!root)
        return 0;
    int left = longestPath(root->left), right = longestPath(root->right);
    // 如果存在左子节点和根节点同值，更新左最长路径;否则左最长路径为0
    if (root->left && root->val == root->left->val)
        left++;
    else
        left = 0;
    if (root->right && root->val == root->right->val)
        right++;
    else
        right = 0;
    res = max(res, left + right);
    return max(left, right);
}
