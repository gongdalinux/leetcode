// 有效括号

#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s){
    stack<int> st;
    if(s.size() % 2 != 0) return false;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') st.push(')');
        else if(s[i] == '[') st.push(']');
        else if(s[i] == '{') st.push('}');
        else if(st.empty() || (st.top()!=s[i])) return false;
        else st.pop();
    }
    return st.empty();
}

bool isValid1(string s) {
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(')');
        else if(s[i]=='[') st.push(']');
        else if(s[i]=='{') st.push('}');
        else if(st.empty()||st.top()!=s[i]) return false;
        else st.pop();
    }
    //第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，故return false ，相反就 return true
    return st.empty();
    }

int main(){
    string s = "({})";
    printf("%d\n", s.size());
    bool flag = isValid(s);
    printf("flag = %d\n", flag);
}