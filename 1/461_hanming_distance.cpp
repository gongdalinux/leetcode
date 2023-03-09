// 汉明距离 两个数位数的不同
#include<iostream>

using namespace std;

int hammingDistance(int x, int y){
    int xr = x ^ y;
    int num = 0;
    while(xr){
        if(xr & 1 == 1) num++;
        xr = xr >> 1;
    }
    return num;
}