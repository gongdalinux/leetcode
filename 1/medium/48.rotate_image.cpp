// 旋转图像

#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    auto new_matrix = matrix;
    int n = matrix.size();
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            new_matrix[j][n-i-1] = matrix[i][j];
        }
    }       
    matrix = new_matrix; 
}