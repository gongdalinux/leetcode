
int hammingWeight(uint32_t n) {
    int ret = 0;
    for(int i=0; i<32; i++){
        if(n & (1<<i)) ret++;
    }   
    return ret;
}

// 观察这个运算：n & (n−1)n~\&~(n - 1)n & (n−1)，其预算结果恰为把 nnn 的二进制位中的最低位的 111 变为 000 之后的结果。
int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            n &= n - 1;
            ret++;
        }
        return ret;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/solution/er-jin-zhi-zhong-1de-ge-shu-by-leetcode-50bb1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。