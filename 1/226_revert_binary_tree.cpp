#include<iostream>

typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

//方法一
TreeNode* invertTree(TreeNode* root){
    if(root == NULL) 
    {
        return NULL;
    }
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->right = left;
    root->left = right;
    return root;
}

//方法二
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}