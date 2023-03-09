
std::vector<string> path;

string smallestFromLeaf(TreeNode* root) {
    dfs(root, "");
    sort(path.begin(), path.end());
    return path[0];
}

void dfs(TreeNode* root, string s){
    if(root == nullptr) return;
    s += 'a' + root->val;
    if((root->left == nullptr) && (root->right == nullptr)){
        reverse(s.begin(), s.end());
        path.emplace_back(s);
        return;
    }
    dfs(root->left, s);
    dfs(root->right, s);
}