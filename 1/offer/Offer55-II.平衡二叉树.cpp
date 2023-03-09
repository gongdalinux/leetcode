// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

bool isBalanced(TreeNode* root) {
    if(root == nullptr) return true;
    // bool res = abs(depth(root->left) - depth(root->right)) <= 1;
    // if(res == false) return false;
    // return isBalanced(root->left) && isBalanced(root->right);
    return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int depth(TreeNode* root){
    if(root == nullptr) return 0;
    return max(depth(root->left), depth(root->right)) + 1; 
}