
string reverseWords(string s) {
    int n = s.size(), l, r = n - 1;
    string ret;
    while(r >= 0){  
        while(r >= 0 && s[r] == ' ') --r; // clear spaces
        if(r < 0) break;
        for(l = r; l >= 0 && s[l] != ' '; --l); // fetch word
        ret += (s.substr(l + 1, r - l) + " ");
        r = l;
    }
    if(ret.size()) ret.pop_back();
    return ret;
}

作者：nobodyyyyy
链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/solution/jian-zhi-offer-58-i-fan-zhuan-dan-ci-shu-vvjl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


string reverseWords(string s) {
        stack<string> tmp;
    for (int i = 0; i < s.size(); ++i)
    {
        int index = i;
        while (i < s.size() && s[i] != ' ')
        {
            ++i;
        }
        if (i != index) tmp.push(s.substr(index, i - index));
    }
    string ans;
    while (!tmp.empty())
    {
        ans += tmp.top() + " ";
        tmp.pop();
    }
    return ans.substr(0, ans.size() - 1);
}

作者：LonelyTaoist
链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/solution/fan-zhuan-dan-ci-shun-xu-zhan-orshuang-z-d0sf/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}