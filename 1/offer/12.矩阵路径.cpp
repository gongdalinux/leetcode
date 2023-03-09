// 单词搜索

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& b, string& w, int i, int j, int k) {
        if (i >= b.size() || i < 0 || j >= b[0].size() || j < 0 || b[i][j] != w[k])
            return false;
        if (k == w.length() - 1)
            return true;
        char temp = b[i][j];
        b[i][j] = '/';
        bool res = dfs(b, w, i + 1, j, k + 1) || 
                   dfs(b, w, i - 1, j, k + 1) || 
                   dfs(b, w, i, j + 1, k + 1) || 
                   dfs(b, w, i, j - 1, k + 1);
		/*
		可以这么写，比较好：
		int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int q = 0; q < 4; q ++ ) {
            int m = i + dx[q], n = j + dy[q];
            if (dfs(b, w, m, n, k + 1)) return true;
        }
		*/
        b[i][j] = temp;
        return res;
    }
};
