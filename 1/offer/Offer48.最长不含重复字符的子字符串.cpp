// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

int lengthOfLongestSubstring(string s) {
    int max=0;
    int res = 0;
    int j=0;
    vector<int> dp(s.size());
    dp[0] = 1;
    for(int i=1; i<s.size(); i++){
        if(s.substr(j, i).find(s[i]) != 1){
            dp[i] = dp[i-1] + 1;
            continue;
        }
        j = i;
        res = max(res, max);
    }
}

int lengthOfLongestSubstring(string s) {
    int size = s.size();//原始串的长度
    string str = "";//子串
    int max = 0;//最长子串的长度
    int t;//保存 当前字符在子串中出现的位置
    for(int i = 0;i < size;i++)
    {
        t = str.find(s[i]);//查找 当前字符在子串中出现的位置
        if(t != -1)//如果出现了
        {
            if(max < str.size())//判断当前子串 与 历史最长串的大小
                max = str.size();
            str.erase(0,t+1);//去掉前t+1个字符
        }
        str += s[i];//不管有没有出现，都需要将当前的字符添加到子串中
    }
    if(max < str.size())//最终还是要判断一次，因为如果从来都没有重复过的话，就不会进入if(t != -1)，也不会更新max了
        max = str.size();
    return max;
}

作者：stu-1d
链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/hua-dong-chuang-kou-chao-xiang-xi-bu-yon-c1rx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。