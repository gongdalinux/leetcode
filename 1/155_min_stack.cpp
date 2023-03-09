#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

class MinStack {
public:
    std::stack<std::pair<int, int>> s;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(s.size() == 0) s.push({x, x});
        else s.push({x, min(x, s.top().second)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

class MinStack {
public:
    std::stack<int> s;
    std::stack<int> min_s;
    /** initialize your data structure here. */
    MinStack() {
        min_s.push(INT_MAX);
    }
    
    void push(int x) {
        s.push(x);
        min_s.push(min(x, min_s.top()));
    }
    
    void pop() {
        s.pop();
        min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};