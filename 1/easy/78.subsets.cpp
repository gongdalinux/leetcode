#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    if (nums.size() == 0) return {{}};
    int n = nums.back();
    printf("n = %d\n", n);
    nums.pop_back();
    vector<vector<int>> res = subsets(nums);

    int size = res.size();
    printf("size = %d\n", size);
    for(int i=0; i<size; i++){
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}

int main(){
    vector<int> Nums = {1, 2};
    vector<vector<int>> results = subsets(Nums);
    printf("results.size() = %d\n", results.size());
    return 0;
}