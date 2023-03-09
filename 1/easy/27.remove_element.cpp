// 移除元素
/*
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
*/

#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int i = 0;
    for(int j=0; j<n; j++){
        if(nums[j] != val){
            nums[i++] = nums[j];
        }
    }
    return i;
}