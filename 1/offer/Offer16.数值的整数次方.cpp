
// double y = 1.0;

// double mPow(double x, int n, int k){
//     if(k >= n) return 1.0;
//     y = x * mPow(x, n, k+1);
//     return y;
// }

// double myPow(double x, int n) {
//     if(n == 0) return 1.0;
//     else if (n > 0) return mPow(x, n, 0);
//     else {
//         double z = 1 / x;
//         return mPow(z, -n, 0);
//     }
// }
#include<iostream>

using namespace std;

double myPow(double x, int n) {
    if(n == 0) return 0.0;
    if(n == 1) return x;
    if(n == -1) return 1/x;
    // if(n < 0){
    //     n = -n;
    //     x = 1/x;
    // }
    if(n%2 == 0){
        double y = myPow(x, n/2);
        return y*y;
    }
    else{
        double y = myPow(x, (n-1)/2);
        return y*y*x;
    }
}

int main(){
    double x = 0.5;
    int n = 5;
    double z = myPow(x, n);
    printf("z = %f\n", z);
    return 0;
}
