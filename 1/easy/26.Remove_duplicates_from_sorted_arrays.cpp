// 删除有序数组重复元素
/*
输入：nums = [1,1,2]
输出：2, nums = [1,2]
*/


#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    if(n == 0) return 0;
    for(int j=0; j<n; j++){
        if(nums[i] != nums[j]){
            nums[++i] = nums[j];
        }
    }
    return i+1;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int n = removeDuplicates(nums);
    printf("n = %d\n", n);
    for(int i=0; i<n; i++){
        printf("nums[i] = %d\n", nums[i]);
    }
}