// 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
// 输出: 2

#include<iostream>
#include<vector>
using name 

// int majorityElement(vector<int>& nums) {
//     unordered_map<int, int> map;
//     for(auto num:nums){
//         map[num]++;
//     }
//     // for(auto it:map){
//     //     int first = it.first;
//     //     int second = it.second;
//     //     if(second > nums.size() / 2){
//     //         return first;
//     //         break;
//     //     }
//     // }
//     for(unordered_map<int, int>::iterator it=map.begin(); it!=map.end(); it++){
//         int first = it->first;
//         int second = it->second;
//         if(second > nums.size() / 2){
//             return first;
//             break;
//         }
//     }
//     return -1;
// }

int majorityElement(vector<int>& nums) {
    int candidate = -1;
    int count = 0;
    for (int num : nums) {
        if (num == candidate)
            ++count;
        else if (--count < 0) {
            candidate = num;
            count = 1;
        }
    }
    return candidate;
}

int main(){
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int res = majorityElement(nums);
}
