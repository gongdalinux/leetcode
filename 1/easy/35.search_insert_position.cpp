// 搜索插入位置
/*
Input: nums = [1,3,5,6], target = 5
Output: 2
Input: nums = [1,3,5,6], target = 2
Output: 1
Input: nums = [1,2,3,5,6], target = 2
Output: 1
*/

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0;
    int h = n;
    if(target > nums[n-1]) return n;
    while(l < h){
        int m = l + (h - l) / 2;
        if(target < nums[m]){
            h = m;
        }
        else if(target > nums[m]){
            l = m + 1;
        }
        else return m;      
    }
    return l;
}