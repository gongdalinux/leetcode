// 二叉树中序遍历

#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inOrder(TreeNode *root, vector<int>& nums);

vector<int> inorderTraversal(TreeNode* root){
    vector<int> nums;
    inOrder(root, nums);
    return nums;
}

void inOrder(TreeNode *root, vector<int>& nums){
    if(root == NULL) return;
    inOrder(root->left, nums);
    nums.emplace_back(root->val);
    inOrder(root->right, nums);
}

int main(){
    TreeNode *root = new TreeNode(0);
    TreeNode *node_1 = new TreeNode(1);
    TreeNode *node_2 = new TreeNode(2);

    root->left = node_1;
    root->right = node_2;    
    vector<int> v = inorderTraversal(root);
    for(int i=0; i<v.size(); i++){
        printf("%d\n", v[i]);
    }
}