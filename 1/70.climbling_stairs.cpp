#include<iostream>

using namespace std;

// 方法一：时间太长
int climbStairs(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    int num = climbStairs(n - 1) + climbStairs(n - 2);
    return num;
}

// 方法二
int climbStairs(int n){
    assert(n>0);
    int sum = 0, n1 = 1, n2 = 2;
    if(n<=2) return n;
    for (int i=3; i<=n; i++){
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    } 
    return sum;
}