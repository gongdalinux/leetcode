// s = "abaccdeff"
// 返回 "b"

char firstUniqChar(string s) {
    if(string.size() == 0) return " ";
    unordered_map<char, int> map;
    for(int i=0; i<s.size(); i++){
        map[s[i]]++;       
    }
    for(auto& m:map){
        char c = m.first;
        int num = m.second;
        if(num == 1) return c;
    }
    return '';
}