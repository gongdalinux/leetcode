// 剪绳子
#include<iostream>
#include<vector>

using namespace std;

/*
// 方法一: 数学法
int cuttingRope(int n) {
    if(n <=3 ) return n-1;
    int k = n / 3;
    int m = n % 3;
    if(m==0) return pow(3, k);
    else if(m==1) return pow(3, k-1)*4;
    else return pow(3, k)*2;
}*/

// 方法二：动态规划法

int cuttingRope(int n) 
{
    if(n <= 1)    return 0;
    if(n == 2)    return 1;
    if(n == 3)    return 2;

    vector<int>	result(n + 1,0);

    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;

    for(int i = 4;i <= n;i++)
    {
        for(int j = 1;j <= i / 2;j++)
        {
            result[i] = max(result[j] * result[i - j],result[i]);
            printf("i, result[i] = [%d, %d]\n", i, result[i]);
        }
    }

    return result[n];
}

int cuttingRope(int n) {
        /*
        *  三种特殊情况：
        *  1、长度为1时，没法剪，最大乘积为0
        *  2、长度为2时，最大乘积为1 × 1 = 1
        *  3、长度为3时，最大乘积为1 × 2 = 2
        */
        if (n <= 3) return n - 1;
        /*
        *  创建动态规划数组，所有元素初始化为0
        *  dp[i]表示剪长度为i的绳子所能得到的最大乘积，dp[n]表示长度为n的绳子
        *  所以数组的长度要为n-1
        */
        vector<int> dp(n + 1, 0);
        /*
        *  上面分析过长度小于等于3时存在的特殊情况，
        *  所以当绳子剪过之后，有一段长度小于等于3时，就不应该继续剪，否则乘积就会变小
        *  则在动态规划数组中，小于等于3的索引所指的元素应该等于其索引的值
        *  代表剪过的绳子到这长度就不要继续剪了
        */
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        /* 
        *  外层循环i表示每一段要剪的绳子，去掉特殊情况从4开始
        *  内层循环j表示将绳子剪成长度为j和i-j的两段
        *  （j只需要遍历到i/2就可以了，两边对称的。比如4剪成 1|3 和 3|1 结果是一样的）
        *  这样双层循环就相当于从下向上完成了剪绳子的逆过程
        *  （剪绳子本来是将大段的绳子剪成小段，然后再在每小段上继续剪）
        *  双层循环中外层循环从4开始一直到原始绳子长度n，每一段都到内层循环进行剪绳子
        *  这样就得到长度在[4, n]区间内的每段绳子剪过之后的最大乘积
        *  dp[i]记录当前长度绳子剪过之后的最大乘积
        */
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        /* 返回剪绳子的最大乘积 */
        return dp[n];
    }

int main(){
    int n = 6;
    int res = cuttingRope(n);
    printf("res = %d\n", res);
}
