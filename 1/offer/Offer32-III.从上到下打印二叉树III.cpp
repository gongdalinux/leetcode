// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

vector<vector<int>> res;

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr) return {{}};
    dfs(root, 0);
    return res;
}

void dfs(TreeNode* root, int n){
    if(root == nullptr) return;
    // path.push_back(root->val);
    if(res.size() >= n){
        vector<int> temp;
		res.push_back(temp);
    }
    res[n].push_back(root->val);
    if(n % 2 != 0){
        dfs(root->left, n+1);
        dfs(root->right, n+1);
    }
    else{
        dfs(root->right, n+1);
        dfs(root->left, n+1);
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr) return {};
    queue<TreeNode*> q;
    vector<vector<int>> res;
    int layer = 1;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> path;
        for(int i=0; i<n; i++){
            TreeNode *node = q.front();
            q.pop();
            path.push_back(node->val);
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        res.push_back(path);
    }
    for(int i=0; i<res.size(); i++){
        if(i%2==1) reverse(res[i].begin(), res[i].end());
    }
    return res;
}