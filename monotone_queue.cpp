// 最大滑动窗口 优先队列

#include<iostream>
#include<deque>
#include<vector>

using namespace std;

class MonotonicQueue {
    private:
        deque<int> data;
    public:
        void push(int n) {
            while (!data.empty() && data.back() < n)
                data.pop_back();
            data.push_back(n);
        }

        int max() { return data.front(); }

        void pop(int n) {
            if (!data.empty() && data.front() == n)
                data.pop_front();
        }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        // 284特殊数据结构:单调队列
        if (i < k - 1) {    //先填满窗口的前 k - 1
            window.push(nums[i]);
        } else {    // 窗口向前滑动
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
        }
    }
    return res;
}

int main(){
    vector<int> num = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(num, k);
    for(int i=0; i<result.size(); i++){
        printf("result[i] = %d\n", result[i]);
    }
}