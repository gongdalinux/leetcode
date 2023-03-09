// 排列 输入数组[1, 2, 3] 输出[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]]
#include<iostream>
#include<vector>

using namespace std;
/*
vector<vector<int>> res;

vector<vector<int>> permute(vector<int>& nums){
    vector<int> track;
    trackback(nums, track, res);
    return res; 
}

void trackback(vector<int>& nums, vector<int>& track, vector<vector<int>>& res){
    if(track.size() == nums.size()){
        res.push_back(track);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        track.push_back(nums[i]);
        trackback(nums, track, res);
        track.pop_back();
    }

}*/


bool used[10];
vector<int> row;
vector<vector<int>> rows;

void test(vector<int>& nums, int level){
    if(level >= nums.size()) {
        rows.push_back(row);
        // printf("%d\n", rows.size());
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(used[i]) continue;
        row.push_back(nums[i]);
        // printf("nums[i],i,row.size() = [%d, %d, %d]\n", nums[i],i, row.size());
        used[i] = true;
        test(nums, level+1);
        row.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    test(nums, 0);
    return rows;
}