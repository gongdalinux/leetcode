// 买卖股票的最佳时机
// 输入：[7,1,5,3,6,4]
// 输出：5

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

// 贪心法
int maxProfit(vector<int>& nums){
    int low = INT_MAX, res = 0;
    for(int i=0; i<nums.size(); i++){
        low = min(low, nums[i]);
        res = max(res, nums[i] - low);
    }
    return res;
}

// 暴力法
int maxProfit(vector<int>& nums){
    int max_val = 0;
    for(int i=0; i<nums.size(); i++)
        for(int j=i+1; j<nums.size(); j++){
            max_val = max(max_val, nums[j]-nums[i]);
        }
    return max_val;
}