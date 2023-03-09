// 最长公共前缀
/*
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include<iostream>
#include<vector>

using namespace std;

string longestCommonPredix(vector<string>& strs){
    int len = strs[0].size();
    int count = strs.size();
    for(int i=0; i<len; i++){
        char c = strs[0][i];
        for(int j=1; j<count; j++){
            if(i == strs[j].size() || strs[j][i] != c){
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

