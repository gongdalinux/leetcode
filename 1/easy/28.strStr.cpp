/*
输入：haystack = "hello", needle = "ll"
输出：2
*/

#include<iostream>
#include<string>

using namespace std;

int strStr(string haystack, string needle) {
    int n = needle.size();
    int m = haystack.size();
    if(n == 0) return 0;
    char s = needle[0];
    for(int i=0; i+n<=m; i++){
        bool flag = true;
        for(int j=0; j<n; j++){
            if(haystack[i+j] != needle[j]){
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
    return -1;
}

int main(){
    string haystack = "hello";
    string needle = "lo";
    int num =  strStr(haystack, needle);
    printf("HELLO\n");
    cout << "num = " << num << endl;
}
