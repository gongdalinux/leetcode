// 最大子序列和
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为6 

// 动态规划法 d[i] = max(d[i-1] + num[i], num[i])
int maxSubArray1(vector<int>& nums){
    int res = nums[0], sum = 0;
    for(auto num: nums){
        sum = max(sum+num, num);
        res = max(res, sum);
    }
    return res;
}

// 暴力法
int maxSubArray(vector<int>& nums){
    int res = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        int sum = 0;
        for(int j=i; j<nums.size(); j++){
            sum += nums[j];
            res = max(sum, res);
        }
    }
    return res;
}

// {2, 3, -6, 2, 4}
// 贪心法
int maxSubArray(vector<int>& nums){
    int sum = 0, res = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        res = max(sum, res);
        if(sum < 0) sum = 0;
    }
    return res;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray(nums);
    printf("%d\n", res);
}
