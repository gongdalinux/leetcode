#include<iostream>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 深度优先 方法一
TreeNode* MergeTrees(TreeNode* root1, TreeNode* root2)
{
    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;
    TreeNode *MergeNode = new TreeNode(root1->val + root2->val);
    MergeNode->left = MergeTrees(root1->left, root2->left);
    MergeNode->right = MergeTrees(root1->right, root2->right);
    return MergeNode;
}

// 方法二
TreeNode* MergeTrees(TreeNode* root1, TreeNode* root2)
{
    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;
    root1->val += root2->val;
    root1->left = MergeTrees(root1->left, root2->left);
    root1->right = MergeTrees(root1->right, root2->right);
    return root1;
}

int main()
{
    return 0;
}