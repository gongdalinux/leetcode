#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> nodes;
//     levelTraverse(root, nodes);
//     return nodes;
//     // if(root == NULL) return;
// }

// void levelTraverse(TreeNode *root, vector<vector<int>>& v_nodes){
//     if(root == NULL) return;
//     vector<int> level_node;
//     queue<TreeNode*> q_nodes;
//     q_nodes.push(root);
//     while(!q_nodes.empty()){
//         TreeNode *node = q_nodes.front();
//         level_node.emplace_back(node->val);
//         q_nodes.pop();
//         if(node->left != NULL) q_nodes.push(node->left);
//         if(node->right != NULL) q_nodes.push(node->right);
//     }
// }

vector<vector<int>> levelOrder(TreeNode* root) {
    vector <vector <int>> ret;
    if (!root) {
        return ret;
    }

    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(vector <int> ());
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front(); q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return ret;
}
