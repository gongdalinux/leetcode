// 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为0，可以看成任意数字。A不能视为14。

// 输入: [0,0,1,2,5]
// 输出: True

bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0) {
            n++;
            continue;
        } 
        if(i<nums.size()-1){
            if(nums[i] == nums[i+1]) return false;
        }
    }
    return nums[nums.size()-1] - nums[n] < 5;
}