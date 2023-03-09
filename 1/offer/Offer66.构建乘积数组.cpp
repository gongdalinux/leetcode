// 输入: [1,2,3,4,5]
// 输出: [120,60,40,30,24]

int mul_num(vector<int> a, int i){
    int m = a.size();
    int res = 1;
    for(int j=0; j<n; j++){
        if(j != i) res *= a[j]; 
    }
    return res;
}

vector<int> constructArr(vector<int>& a) {
    int n = a.size();
    if(n==0) return {};
    vector<int> b(n, 0);
    b[0] = 1;
    for(int i=1; i<n; i++){
        b[i] = b[i-1] * a[i-1];
    }
    int tmp = 1;
    for(int i=n-2; i>=0; i--){
        tmp *= a[i+1];
        b[i] *= tmp;
    }
    return b;
}