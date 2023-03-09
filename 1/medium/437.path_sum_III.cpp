// 路径总和III
// 给定一个二叉树，它的每个结点都存放着一个整数值。

// 找出路径和等于给定数值的路径总数。

// 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

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

int count = 0;
int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    dfs(root, targetSum);            //以root为起始点查找路径
    pathSum(root->left, targetSum);  //左子树递归
    pathSum(root->right, targetSum); //右子树递归
    return count;

}

void dfs(TreeNode *root, int sum)
{
    if (!root)
        return;
    sum -= root->val;
    if (sum == 0) //注意不要return,因为不要求到叶节点结束,所以一条路径下面还可能有另一条
        count++;  //如果找到了一个路径全局变量就+1
    dfs(root->left, sum);
    dfs(root->right, sum);
}