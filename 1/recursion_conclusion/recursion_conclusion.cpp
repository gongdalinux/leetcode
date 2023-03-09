#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

bool factorial_flag = false;
bool fib_flag = false;
bool gcb_flag = true;

// 阶乘
int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

// 计算斐波那契数列
int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

// 计算最大公约数
int gcb(int a, int b){
    if(b == 0) return a;
    return gcb(b, a % b);
}

int main(){
    if(factorial_flag == true)
    {
        int n;
        scanf("%d", &n);
        int res = factorial(n);
        printf("factorial :%d \n", res);
    }

    if(fib_flag == true){
        int n;
        scanf("%d", &n);
        int res = fib(n);
        printf("fib: %d \n", res);
    }

    if(gcb_flag == true){
        int a, b;
        scanf("%d %d", &a, &b);
        int res = gcb(a, b);
        printf("gcb: %d \n", res);
    }

    return 0;
}