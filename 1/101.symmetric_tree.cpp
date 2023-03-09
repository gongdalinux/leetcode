#include<iostream>
#include<queue>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 深度优先(递归)
bool check(TreeNode *t1, TreeNode *t2){
    if((t1 == NULL) && (t2 == NULL)) return true;
    if(!t1 || !t2) return false;
    return (t1->val == t2->val) && check(t1->left, t2->right) && check(t1->right, t2->left);
}

bool isSymmetric(TreeNode *root){
    if(root == NULL) return false;
    check(root->left, root->right);
}

// 广度优先(队列)

bool isSymmetric(TreeNode *root){
    queue<TreeNode *> nodes;
    if(root == NULL) return false;
    // nodes.push(root);
    nodes.push(root);
    while(nodes.empty() == false){
        TreeNode *node1 = nodes.front();
        nodes.pop();
        TreeNode *node2 = nodes.front();
        nodes.pop();
        if(!node1 && !node2) continue;
        if(!node1 || !node2) return false;
        if(node1->val != node2->val) return false;
        nodes.push(node1->left);
        nodes.push(node2->right);
        // nodes.push(node1->right);
        // nodes.push(node2->left);
    }
    return true; 
}