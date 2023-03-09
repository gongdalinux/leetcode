

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    std::stack<int> s;
    int i=0;
    for(auto num:pushed){
        s.push(num);
        while(!s.is_empty() && s.top()==popped[i]){
            s.pop();
            i++;
        }
    }
    return s.is_empty();
}