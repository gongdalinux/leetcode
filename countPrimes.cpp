// 计算素数
#include<iostream>

using namespace std;

int countPrimes(int n){
    int count = 0;
    bool isPrime[n] = {true};
    for(int m=0; m<n; m++) isPrime[m] = true;
    for(int i=2; i*i<n; i++){
        if(isPrime[i])
            for(int j=i*i; j<n; j=j+i){
                isPrime[j] = false;
            }
    } 
    for(int a=2; a<n; a++){
        if(isPrime[a]){
            count++;
            printf("prime = %d\n", a);
        }
    }
    return count;
}

int main(){
    int num = 10;
    int c = countPrimes(num);
    printf("c = %d\n", c);
}