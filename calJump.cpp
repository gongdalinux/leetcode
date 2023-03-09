#include<iostream>
#include<vector>

using namespace std;

bool calcJump(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        // 不断计算能跳到的最远距离
        farthest = max(farthest, i + nums[i]);
        // 可能碰到了 0,卡住跳不动了
        if(farthest <=i) return false;
    }
    return farthest == n - 1;
}

int main(){
    vector<int> num = {2,2,1,2,4};
    bool res = calcJump(num);
    printf("res =  %d\n", res);
}