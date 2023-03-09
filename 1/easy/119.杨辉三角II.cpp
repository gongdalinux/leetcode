// 杨辉三角II
// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

#include<iostream>
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    rowIndex = rowIndex + 1;
    vector<vector<int>> vs(rowIndex);
    // vector<int> v;
    for(int i=0; i<rowIndex; i++){
        vs[i].resize(i+1);
        vs[i][0] = vs[i][i] = 1;
        for(int j=1; j<i; j++){
            vs[i][j] = vs[i-1][j-1] + vs[i-1][j];
        }
    }
    return vs[rowIndex-1];
}