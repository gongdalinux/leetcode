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

// 前序遍历
void preOrderTravers(TreeNode *root){
    if(root == NULL) return;
    printf("%d\n", root->val);
    preOrderTravers(root->left);
    preOrderTravers(root->right);
}

// 中序遍历
void inOrderTravers(TreeNode *root){
    if(root == NULL) return;
    inOrderTravers(root->left);
    printf("%d\n", root->val);
    inOrderTravers(root->right);
}

// 后序遍历
void postOrderTravers(TreeNode *root){
    if(root == NULL) return;
    postOrderTravers(root->left);
    postOrderTravers(root->right);
    printf("%d\n", root->val);
}

// 层序遍历
void levelTravers(TreeNode *root){
    if(root == NULL) return;
    queue<TreeNode*> Q;
    Q.push(root);
    while(Q.empty() == false){
        TreeNode *node = Q.front();
        Q.pop();
        printf("%d \n", node->val);
        if(node->left != NULL) Q.push(node->left);
        if(node->right != NULL) Q.push(node->right);
    }
    printf("\n");
}

// 求树高
int getTreeHeight(TreeNode *root){
    if(root == NULL) return 0;
    return max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
}

// 找出节点的层高
bool flag = false;

void getNodeLayer(TreeNode *root, TreeNode *node, int& layer){
    if(root == NULL) return;
    if(flag) return;
    layer++;
    if(root->val == node->val)
    {
        printf("layer = %d\n", layer);
        flag = true;
        return;
    }
    getNodeLayer(root->left, node, layer);
    getNodeLayer(root->right, node, layer);
    layer--;
}

// 找出节点路径
// queue<TreeNode*> q_node;
bool find_flag = false;

void findNodePath(TreeNode *root, TreeNode *node, queue<TreeNode*> &q_node){
    if(root == NULL) return;
    if(find_flag) return;
    q_node.push(root);
    if(root->val == node->val){
        find_flag = true;
        while(q_node.empty() == false){
            TreeNode *node = q_node.front();
            printf("%d - ", node->val);
            q_node.pop();
        }
        return;
    }
    findNodePath(root->left, node, q_node);
    findNodePath(root->right, node, q_node);
    q_node.pop();
}

/*
            0
           / \
          1   2
         / \   \
        3   4   5
           /
          6
           \
            7
*/

int main(){
    TreeNode* root = new TreeNode(0);
    TreeNode* node_1 = new TreeNode(1);
    TreeNode* node_2 = new TreeNode(2);
    TreeNode* node_3 = new TreeNode(3);
    TreeNode* node_4 = new TreeNode(4);
    TreeNode* node_5 = new TreeNode(5);
    TreeNode* node_6 = new TreeNode(6);
    TreeNode* node_7 = new TreeNode(7);

    root->setChildNode(node_1, node_2);
    node_1->setChildNode(node_3, node_4);
    node_2->setChildNode(NULL, node_5);
    node_4->setChildNode(node_6, NULL);
    node_6->setChildNode(NULL, node_7);

    preOrderTravers(root);
    printf("preOrderTravers finished\n");

    inOrderTravers(root);
    printf("inOrderTravers finished\n");

    postOrderTravers(root);
    printf("postOrderTravers finished\n");

    levelTravers(root);
    printf("levelTravers finished\n");

    int tree_height = getTreeHeight(root);
    printf("Tree Height: %d\n", tree_height);

    int layer = 0;
    getNodeLayer(root, node_6, layer);

    queue<TreeNode*> Q_node;
    findNodePath(root, node_6, Q_node);

    return 0;
}