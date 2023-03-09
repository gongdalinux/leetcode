// 有向无环

// 输入：graph = [[1,2],[3],[3],[]]
// 输出：[[0,1,3],[0,2,3]]
// 解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

// 链接：https://leetcode-cn.com/problems/all-paths-from-source-to-target

vector<vector<int>> res;

void traverse(vector<vector<int>>& graph, int n, vector<int>& path){
    path.push_back(n);
    if(n == graph.size() - 1){
        res.push_back(path);
        path.pop_back();
        return;
    }
    for(auto g:graph[n]){
        traverse(graph, g, path);
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    traverse(graph, 0, path);
    return res;
}