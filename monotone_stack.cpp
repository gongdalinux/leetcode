#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size()); // 存放答案的数组
    stack<int> s;
    // printf()
    for (int i = nums.size() - 1; i >= 0; i--) { // 倒着往栈里放
        printf("i, s.top() = [%d]\n", i);
        printf("s.empty() = %d\n", s.empty());
        while (!s.empty() && s.top() <= nums[i]) { // 判定个子高矮
                s.pop(); // 矮个起开,反正也被挡着了。。。
            }
        ans[i] = s.empty() ? -1 : s.top(); // 这个元素身后的第一个高个
        printf("ans[i] = %d\n", ans[i]);
        s.push(nums[i]); // 进队,接受之后的身高判定吧!
    }
    // printf("s.empty() = %d\n", s.empty());
    while(s.empty() == 0){
        printf("s.top() = %d\n", s.top());
        s.pop();
    }
    return ans;
}

int main(){
    vector<int> a = {2,1,2,4,3};
    vector<int> res = nextGreaterElement(a);
    return 0;
}