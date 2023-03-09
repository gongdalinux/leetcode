TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return nullptr;
    if((root == p) || (root == q)) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    // 左右子树均存在p或q
    if(left != nullptr && right != nullptr) return root;
    // 左孩子不存在p或q, 在右边有LCA, 返回的是最近公共祖先节点，是答案
    if(left == nullptr) return right;
    if(right == nullptr) return left;
    return nullptr;
}