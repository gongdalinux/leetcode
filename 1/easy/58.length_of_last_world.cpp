// 最后一个单词长度

/*
输入：s = "Hello World"
输出：5
*/

#include<iostream>
#include<string>

using namespace std;

/*
int lengthOfLastWord(string s) {
    int n = s.size();
    if(n == 0) return 0;
    int len = 0;
    bool flag = true;
    for(int i=0; i<n; i++){
        if(s[i] == ' '){
            cout << "i = " << i << endl;
            flag = false;
            len = n - 1 - i;
        }
    }
    if(flag) return n;
    return len;
}
*/
int lengthOfLastWord(string s) {
    int n = s.size();
    if(n == 0) return 0;
    int count = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == ' '){
            if(count == 0) continue;
            break;
        }
        count++;
    }
    return count;        
}

int main(){
    string s = "a ";
    printf("s.size() = %d\n", s.size());
    int len = lengthOfLastWord(s);
    cout << "len = " << len << endl;
}

