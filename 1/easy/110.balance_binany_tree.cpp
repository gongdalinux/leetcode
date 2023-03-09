// 平衡二叉树

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

bool treeH(TreeNode* root, int h){
    if(root==nullptr) return h; 
    h += 1;
    int h_left = treeH(root->left, h);
    int h_right = treeH(root->right, h);
    h -= 1;
    return (h_left - h_right < 2) && (h_left - h_right > -2);
}

bool isBalanced(TreeNode* root) {
    int hei = 0;
    return treeH(root, hei);
}

int height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return max(height(root->left), height(root->right)) + 1;
    }
}

bool isBalanced(TreeNode* root) {
    if (root == NULL) {
        return true;
    } else {
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
}


