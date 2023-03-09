


vector<int> levelOrder(TreeNode* root) {
    if(root == nullptr) return {};
    queue<TreeNode*> q;
    vector<int> res;
    q.push(root);
    while(q.size() != 0){
        for(int i=0; i<q.size(); i++){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    }
    return res;
}

void dfs(TreeNode* root, int n){
    if(root == nullptr) return;

}