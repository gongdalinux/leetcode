// 滑动串口最大值
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> max_v;
    for(int i=0; i<nums.size()-k+1; i++){
        int j = 0;
        int max_val = INT_MIN;
        for(j=i; j<k+i; j++){
            max_val = max(max_val, nums[j]);
        }
        max_v.emplace_back(max_val);
    }
    return max_v;
}

int main(){
    int k = 3;
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    // vector<int> v = {7,2,4};
    vector<int> res = maxSlidingWindow(v, k);
    for(auto i:res){
        printf("%d\n", i);
    }
}