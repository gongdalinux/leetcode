// 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
// 输入：nums = [9,1,7,9,7,9,7]
// 输出：1

 int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 2; i += 3)
        if (nums[i] != nums[i + 2]) return nums[i];
    return nums.back();
}

作者：fengziluo
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/3chong-jie-fa-ji-jian-cdai-ma-by-fengzil-fmlr/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。