// 罗马数字转整数
/*
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int romanToInt(string s){
    int len = s.length();
    unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int result = 0;
    for(int i=0; i<len; i++){
        int value = map[s[i]];
        if((i<len-1) && value < map[s[i+1]]){
            result -= value;
        }
        else{
            result += value;
        }
    }
    return result;
}

int main(){
    string s = "MCMXCIV";  // 1994
    int ans = romanToInt(s);
    cout << "ans = " << ans << endl;   
}