// 移动零 
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]

#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    if(nums.empty() == true) {
        return;
    }
    //两个指针i和j
    int j = 0;
    for(int i=0;i<nums.size();i++) {
        //当前元素!=0，就把其交换到左边，等于0的交换到右边
        if(nums[i]!=0) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j++] = tmp;
            printf("j = %d\n", j);
        }
    }
    for(auto num:nums) printf("%d\n", num);
}

void moveZeroes(vector<int>& nums) {
    if(nums.empty() == true) {
        return;
    }
    //第一次遍历的时候，j指针记录非0的个数，只要是非0的统统都赋给nums[j]
    int j = 0;
    for(int i=0;i<nums.size();++i) {
        if(nums[i]!=0) {
            nums[j++] = nums[i];
        }
    }
    //非0元素统计完了，剩下的都是0了
    //所以第二次遍历把末尾的元素都赋为0即可
    for(int i=j;i<nums.size();++i) {
        nums[i] = 0;
    }
}

void moveZeroes1(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0){
            for(int j = i; j<nums.size(); j++){
                // if()
                int temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
            }
        }
    }
    for(auto num:nums) printf("%d\n", num);     
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
}