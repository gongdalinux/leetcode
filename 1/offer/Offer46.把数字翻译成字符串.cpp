


int translateNum(int num) {
    // String s = String.valueOf(num);
    string s = to_string(num);
    int a = 1, b = 1;
    for(int i = 2; i <= s.size(); i++) {
        string tmp = s.substr(i - 2, 2);
        int c = tmp >= "10" && tmp <= "25" ? a + b : a;
        b = a;
        a = c;
    }
    return a;
}

作者：jyd
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/mian-shi-ti-46-ba-shu-zi-fan-yi-cheng-zi-fu-chua-6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

public int translateNum(int num) {
    int a = 1, b = 1, x, y = num % 10;
    while(num != 0) {
        num /= 10;
        x = num % 10;
        int tmp = 10 * x + y;
        int c = (tmp >= 10 && tmp <= 25) ? a + b : a;
        b = a;
        a = c;
        y = x;
    }
    return a;
}

作者：jyd
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/mian-shi-ti-46-ba-shu-zi-fan-yi-cheng-zi-fu-chua-6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。