// 有效回文串

// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

#include<iostream>
#include<string>

using namespace std;

bool isCharOrDigit(char c){
    printf("c = %c\n", c);
    if(((c <= '9')&&(c >= '0')) || ((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A'))) return true;
    printf("1c = %c\n", c);
    return false;
}

bool isPalindrome(string s) {
    int end = s.size() - 1;
    int start = 0;
    while(start < end){
        // if(!isCharOrDigit(s[start])){
        //     start++;
        //     continue;
        // }
        // if(!isCharOrDigit(s[end])){
        //     end--;
        //     continue; 
        // }
        if(!isalnum(s[start])){
            start++;
            continue;
        } 
        if(!isalnum(s[end])){
            end--;
            continue;
        }       

        if(tolower(s[start]) != tolower(s[end])) return false;
        start++;
        end--;
        // continue;
    }
    return true;
}

int main(){
    string s = "0P";
    // char a = 'a';
    // char A = 'A';
    // if(a == A + 32) {
    //     printf("right\n");
    // }
    bool flag = isPalindrome(s);
    printf("flag = %d\n", flag);
}