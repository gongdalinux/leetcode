// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

// BFS
vector<vector<int>> levelOrder(TreeNode* root) {
    // if(root == nullptr) return {};
    vector<vector<int>> res;
    queue<TreeNode*> q;
    if(root != nullptr)q.push(root);
    // layer.push_back(root->val);
    // res.push_back(layer);
    while(q.size() != 0){
        vector<int> layer;
        int n = q.size();
        for(int i=0; i<n; i++){
            TreeNode* node = q.front();
            q.pop();
            layer.push_back(node->val);
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        res.push_back(layer);
    }
}

// DFS
vector<vector<int>> res;

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr) return {};
    dfs(root, 0);
    return res;    
}

void dfs(TreeNode* root, int height){
    if(root == nullptr) return;
    print("height, res.size() = [%d, %d]\n", height, res.size());
    if(height >= res.size()) {
        vector<int> temp;
		res.push_back(temp);
    }
    res[height].push_back(root->val);
    dfs(root->left, height+1);
    dfs(root->right, height+1);
}
    
