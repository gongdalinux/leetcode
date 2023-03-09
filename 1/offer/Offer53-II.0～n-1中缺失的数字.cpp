
// 输入: [0,1,2,3,4,5,6,7,9]
// 输出: 8

int missingNumber(vector<int>& nums) {
    int res = 0;
    if (nums[0]==1) return 0;
    for(int i=0; i<nums.size(); i++){
        if(i != nums[i]) return i;
    }
    return nums.size();
}

// 二分法
int missingNumber(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;
    while(i <= j) {
        int m = (i + j) / 2;
        if(nums[m] == m) i = m + 1;
        else j = m - 1;
    }
    return i;
}