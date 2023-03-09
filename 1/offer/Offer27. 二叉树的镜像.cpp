// 二叉树的镜像

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class TreeNode{
public:
    int val; 
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val = x;
        // left = NULL;
        // right = NULL;
    }

    void setChildNode(TreeNode *lChild, TreeNode *rChild){
        left = lChild;
        right = rChild;
    }
};


 // TreeNode* mirrorTree(TreeNode* root) {
    //     if(!root) return nullptr;
    //     // TreeNode *tmp;
    //     TreeNode *tmp = root->left;
    //     root->left = root->right;
    //     root->right = tmp;
    //     mirrorTree(root->left);
    //     mirrorTree(root->right);
    //     return root;
    // }

TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* left = mirrorTree(root->left);
    TreeNode* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    printf("left, right = [%d, %d]\n", left->val, right->val);
    return root;
}

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node_1 = new TreeNode(3);
    TreeNode* node_2 = new TreeNode(10);
    TreeNode* node_3 = new TreeNode(1);
    TreeNode* node_4 = new TreeNode(4);
    TreeNode* node_5 = new TreeNode(7);
    TreeNode* node_6 = new TreeNode(12);
    // TreeNode* node_7 = new TreeNode(7);

    root->setChildNode(node_1, node_2);
    node_1->setChildNode(node_3, node_4);
    node_2->setChildNode(node_5, node_6);
    // node_4->setChildNode(node_6, NULL);
    // node_6->setChildNode(NULL, node_7);
    mirrorTree(root);
}