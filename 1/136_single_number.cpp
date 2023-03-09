// 只出现一次的数字
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int singleNumber(vector<int>& nums){
    // unordered_map<int, int> map;
    unordered_set<int> sets;
    for(int num :nums){
        // map[num]++;
        if(sets.count(num)) sets.erase(num);
        else sets.insert(num);
    }
    return *(sets.begin());
}


int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int num:nums){
        res ^= num;
    }
    return res;
}
