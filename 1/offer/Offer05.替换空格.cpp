// 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

// 输入：s = "We are happy."
// 输出："We%20are%20happy.

#include<iostream>
#include<vector>

using namespace std;

string replaceSpace(string s) {
    string st;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] == ' ') {
            st.push_back('%');
            st.push_back('2');
            st.push_back('0');

        }
        else st.push_back(s[i]);
    }
    return st;
}

int main(){
    string s = "We are happy.";
    string st = replaceSpace(s);
    printf("st = %s\n", st);
}

