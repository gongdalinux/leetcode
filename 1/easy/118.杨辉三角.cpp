// 杨辉三角

/*
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> vs;
    // vector<int> v;
    for(int i=0; i<numRows; i++){
        // v = gen(v, i);
        // vs.push_back(v);
        // vs[i].resize(i);
        vector<int> v(i+1, 0);
        v[0] = 1;
        v[i] = 1;
        // vs[i][0] = 1;
        // vs[i][i] = 1;
        if(i>1){
            for(int j=1; j<i; j++)
            v[j] = vs[i-1][j-1] + vs[i-1][j];
            // vs[i][j] = vs[i-1][j-1] + vs[i-1][j];
        }    
        vs.push_back(v);  
    }
    return vs;    
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> vs(numRows);
    for(int i=0; i<numRows; i++){
        vs[i].resize(i+1);
        vs[i][0] = 1;
        vs[i][i] = 1;
        for(int j=1; j<i; j++)
            vs[i][j] = vs[i-1][j-1] + vs[i-1][j];
          
    }
    return vs;    
}

int main(){
    int n = 2;
    vector<vector<int>> res = generate(n);
    printf("res.size() = %d\n", res.size());
}