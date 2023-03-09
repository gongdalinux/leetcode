#include<iostream>
#include<vector>

using namespace std;

int step = 0;
int r_pre = 0;
int c_pre = 0;

int moveStep(int r, int c, int m, int n, int k){
    if(r > m-1 || r<0 || c<0 || c > n-1 || r_pre+c_pre+r+c > k) return 0;
    step++;
    r_pre = r;
    c_pre = c;
    int flag = moveStep(r+1, c, m, n, k) || moveStep(r-1, c, m, n, k) || moveStep(r, c-1, m, n, k) || moveStep(r, c+1, m, n, k);
    // step--;
    return flag;
}

int movingCount(int m, int n, int k) {
    moveStep(0, 0, m, n, k);
    return step;
}