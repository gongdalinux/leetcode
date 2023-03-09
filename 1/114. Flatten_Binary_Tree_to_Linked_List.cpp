#include<iostream>
#include<vector>

using namespace std;

// 二叉树展开为TreeNode类型链表 展开后的链表与二叉树先序遍历相同
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void flatten(TreeNode *root){
    vector<TreeNode*> v;
    preOrder(root, v);
    for(int i=1; i<v.size(); i++){
        TreeNode* pre = v[i-1];
        TreeNode* cur = v[i];
        pre->left = NULL;
        pre->right = cur;
    }
}

void preOrder(TreeNode* node, vector<TreeNode*>& v_nodes){
    if(node == NULL) return;
    v_nodes.push_back(node);
    preOrder(node->left, v_nodes);
    preOrder(node->right, v_nodes);
}
