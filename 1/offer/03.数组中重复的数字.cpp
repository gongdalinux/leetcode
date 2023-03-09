// 找出数组中重复的数字

// 输入：
// [2, 3, 1, 0, 2, 5, 3]
// 输出：2 或 3 


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, int> m;
    int n = nums.size();
    for(int i=0; i<n; i++){
        m[nums[i]]++;
    }    
    for(unordered_map<int, int>::iterator a=m.begin(); a!=m.end(); a++){
        if(a->second > 1) return a->first;
    }
    for(auto& a:m){
        if(a.second > 1) return a.first;
    }
    return -1;
}