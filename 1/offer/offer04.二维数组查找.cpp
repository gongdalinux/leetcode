// 二维数组的查找

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int r = 0;
        if(matrix.size() == 0) return false;
        int c = matrix[0].size() - 1;
        while(r<matrix.size() && c>=0){
            if(matrix[r][c] > target) c--;
            else if(matrix[r][c] < target) r++;
            else if(matrix[r][c] == target) return true;
        }
        return false;
    }
};