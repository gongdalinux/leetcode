// 比特位计数
// 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
// 输入: 5
// 输出: [0,1,1,2,1,2]

#include<iostream>
#include<vector>

using namespace std;

vector<int> countBits(int num) {
    vector<int> result(num+1);
    result[0] = 0;
    for(int i = 1; i <= num; i++)
    {
        if(i % 2 == 1)
        {
            result[i] = result[i-1] + 1;
        }
        else
        {
            result[i] = result[i/2];
        }
    }
    
    return result;
}

vector<int> countBits(int num) {
    vector<int> bits(num + 1);
    for (int i = 1; i <= num; i++) {
        bits[i] = bits[i >> 1] + (i & 1);
    }
    return bits;
}