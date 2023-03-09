// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

string reverseLeftWords(string s, int n) {
    string res;
    if(n==0) return s;
    for(int i=n; i<s.size(); i++) res += s[i];
    for(int i=0; i<n; i++) res += s[i];
    return res;
}