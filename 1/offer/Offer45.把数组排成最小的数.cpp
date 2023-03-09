// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

// 输入: [10,2]
// 输出: "102"

// 输入: [3,30,34,5,9]
// 输出: "3033459"

string minNumber(vector<int>& nums) {
    vector<string> strs;
    for(int i = 0; i < nums.size(); i++)
        strs.push_back(to_string(nums[i]));
    quickSort(strs, 0, strs.size() - 1);
    string res;
    for(string s : strs)
        res.append(s);
    return res;
}

void quickSort(vector<string>& strs, int l, int r) {
    if(l >= r) return;
    int i = l, j = r;
    while(i < j) {
        while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j) j--;
        while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j) i++;
        swap(strs[i], strs[j]);
    }
    swap(strs[i], strs[l]);
    quickSort(strs, l, i - 1);
    quickSort(strs, i + 1, r);
}

作者：jyd
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。