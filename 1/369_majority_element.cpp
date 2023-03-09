// 多数元素 在数组中某个元素出现超过n/2次数
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// 方法一
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int max_val = 0;
    int dex = 0;
    for(auto num: nums) {
        map[num]++;
        if(map[num] > max_val){
            max_val = map[num];
            dex = num;
        }
    }
    return dex;
}

// 方法二
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2]
}