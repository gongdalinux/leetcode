#include<iostream>

using namespace std;

int add(int& h){
    h += 1;
    printf("h = %d\n", h);
}

int main(){
    // int a = 10*3;
    // int b = 5 / 2;
    // printf("a, b = [%d, %d]\n", a, b);
    int k = 1;
    add(k);
}