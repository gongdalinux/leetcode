unordered_set<string> res;
string track;
// vector<bool> used(100, false);
// bool used[100];
unordered_map<int, bool> used;

vector<string> permutation(string s) {
    // vector<string> ret;
    dfs(s);
    vector<string> ret(res.begin(), res.end());
    // for(auto& r:res) ret.push_back(r);
    return ret;
}

void dfs(string s){
    if(track.size() == s.size()) {
        res.insert(track);
        return;
    }
    for(int i=0; i<s.size(); i++){
        if(used[i]) continue;
        track.push_back(s[i]);
        used[i] = true;
        dfs(s);
        used[i] = false;
        track.pop_back();
    }
}
