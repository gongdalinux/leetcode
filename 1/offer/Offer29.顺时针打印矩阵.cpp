// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.size() == 0) return {};
    int down = matrix.size() - 1;
    int right = matrix[0].size() - 1;
    int left = 0;
    int up = 0;
    while(true){
        for(int i=left; i<=right; i++){
            res.push_back(matrix[up][i]);
        }
        if(++up > down) break;
        for(int i=up; i<=down; i++){
            res.push_back(matrix[i][right]);
        }
        if(--right < left) break;
        for(int i=right; i>=left; i--){
            res.push_back(matrix[down][i]);
        }
        if(--down < up) break;
        for(int i=down; i>=up; i--){
            res.push_back(matrix[i][left]);
        }
        if(++left > right) break;
    }
    return res;
}