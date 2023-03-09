// 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

int maxSubArray(vector<int>& nums) {
    int n = nums.size(); 
    int max_num = 0;
    int res = nums[0];
    for(int i=0; i<n; i++){
        max_num = max(max_num + nums[i], nums[i]);
        res = max(res, max_num);
    }
    return res;
}