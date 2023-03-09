// 加一
// 输入：digits = [1,2,3]
// 输出：[1,2,4]
// 解释：输入数组表示数字 123。

#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for(int i=n-1; i>=0; i--){
        digits[i] += 1;
        digits[i] %= 10;
        if(digits[i] != 0){
             return digits;
        }
    }
    // digits.insert(digits.begin(),1);
    vector<int> tmp(n+1, 0);
    tmp[0] = 1;
    return tmp;
}
