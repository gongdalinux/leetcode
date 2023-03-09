// 输入：nums = [1,2,3,4]
// 输出：[1,3,2,4] 
// 注：[3,1,2,4] 也是正确的答案之一。

vector<int> exchange(vector<int>& nums) {
    int n = nums.size();
    int m = 0;
    for(int i=0; i<n; i++){
        if(nums[i] % 2) {
            swap(nums[i], nums[m]);
            m++;
        }
    }
    return nums;
}

vector<int> exchange(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while(left < right){
        if(nums[left] % 2){
            left++;
            continue;
        }
        if(nums[right] % 2 == 0){
            right--;
            continue;
        }
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
    return nums;
}