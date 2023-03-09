// 子集
// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

#include<iostream>
#include<vector>

using namespace std;

vector<int> t;
vector<vector<int>> ans;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        t.clear();
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                t.push_back(nums[i]);
                printf("[%d, %d, %d]\n", mask, i, nums[i]);
            }
        }
        ans.push_back(t);
    }
    return ans;
}

// vector<vector<int>> subsets(vector<int>& nums) {
    
// }

// void traceback(vector<int>& nums, int layer){

//     for(int i=0; i<nums.size(); i++){

//     }

// }

int main(){
    vector<vector<int>> res;
    vector<int> nums = {11, 22, 33};
    res = subsets(nums);
}