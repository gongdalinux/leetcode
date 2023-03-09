#include<stdio.h>
#include<iostream>
#include<initializer_list>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
public:
    int val;
    vector<TreeNode*> childs;

    TreeNode(int data) {
        val = data;
    }
    void setChildNode(initializer_list<TreeNode *> list){
        for(TreeNode* l:list){
            childs.push_back(l);
        }
    }
};

void preOrderTraverse(TreeNode *root){
    if(root == NULL) return;
    printf("%d\n", root->val);
    for(TreeNode* l: root->childs)
    {
        preOrderTraverse(l);
    }
}

// void inOrderTraverse(TreeNode *root){
// }

void postOrderTraverse(TreeNode *root){
    if(root == NULL) return;
    for(TreeNode* l: root->childs)
    {
        preOrderTraverse(l);
    }
    printf("%d\n", root->val);
}

// 层序
void levelOrder(TreeNode *root){
    queue<TreeNode*> nodes;
    if(root == NULL) return;
    nodes.push(root);
    while(nodes.empty() == false){
        TreeNode *node = nodes.front();
        printf("%d\n", node->val);
        nodes.pop();
        for(TreeNode* n: node->childs){
            if(n != NULL) nodes.push(n);
        }
    }
}

int main(){
    TreeNode *root = new TreeNode(0);
    TreeNode *node_1 = new TreeNode(1);
    TreeNode *node_2 = new TreeNode(2);
    TreeNode *node_3 = new TreeNode(3);
    TreeNode *node_4 = new TreeNode(4);
    TreeNode *node_5 = new TreeNode(5);
    TreeNode *node_6 = new TreeNode(6);
    TreeNode *node_7 = new TreeNode(7);
    TreeNode *node_8 = new TreeNode(8);
    TreeNode *node_9 = new TreeNode(9);

    root->setChildNode({node_1, node_2, node_3});
    node_1->setChildNode({node_7, node_5, node_6});
    node_3->setChildNode({node_4});
    node_7->setChildNode({node_8, node_9});

    preOrderTraverse(root);
    printf("preOrderTraverse finished \n");

    postOrderTraverse(root);
    printf("preOrderTraverse finished \n"); 

    levelOrder(root);
}
