
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int j = nums.size() - 1;
    int i = 0;
    while(i<j){
        while((i<j) && (nums[i] + nums[j]  < target)) i++;
        while((i<j) && (nums[i] + nums[j]  > target)) j--;
        if(nums[i] + nums[j] == target){
            res.push_back(nums[i]);
            res.push_back(nums[j]);
            return res;
        }
    }
    return res;
}