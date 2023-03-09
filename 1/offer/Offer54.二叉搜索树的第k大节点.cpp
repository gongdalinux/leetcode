// 给定一棵二叉搜索树，请找出其中第k大的节点。

// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 4

// 中序遍历
void inOrder(TreeNode* root, vector<int>& res){
    if(root == nullptr) return;
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
}

int kthLargest(TreeNode* root, int k) {
    vector<int> res;
    inOrder(root, res);
    return res[res.size() - k];
}

// 中序倒序遍历
void inOrder(TreeNode* root, int& k){
    if(root == nullptr) return;
    inOrder(root->right,  k);
    if(--k == 0) {
        res = root->val;
        return;
    }
    inOrder(root->left, k);
}

int res;
int kthLargest(TreeNode* root, int k) {
    inOrder(root, k);
    return res;
}
