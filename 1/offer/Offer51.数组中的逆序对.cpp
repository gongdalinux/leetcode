// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

int reversePairs(vector<int>& nums) {
    int len = nums.size();
    int n = 0;
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(nums[i] > nums[j]) n++;
        }
    }
    return n;
}