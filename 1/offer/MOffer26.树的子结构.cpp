// 树的子结构

// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。

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
        left = NULL;
        right = NULL;
    }

    void setChildNode(TreeNode *lChild, TreeNode *rChild){
        left = lChild;
        right = rChild;
    }
};

bool isSameTree(TreeNode* A, TreeNode* B){
    if(!A && !B) return true;
    if(!A || !B) return false;
    if(A->val != B->val) return false;
    bool res = isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    return res;
}

bool dfs(TreeNode* A, TreeNode* B) {
    if(!B) return true;
    if(!A || A->val != B->val) return false;
    return dfs(A->left, B->left) && dfs(A->right, B->right);
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(!A || !B) return false;
    return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}