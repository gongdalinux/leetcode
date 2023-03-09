#include<iostream>
#include<queue>
#include<vector>

// 全排列

using namespace std;

vector<vector<int>> rows;
bool used[10];

vector<int> row;

void test(vector<int>& nums, int level);

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

int main(){
    vector<int> a = {1, 2, 3, 4};
    vector<vector<int>> b = permute(a);
    printf("b = %d\n", b.size());
}