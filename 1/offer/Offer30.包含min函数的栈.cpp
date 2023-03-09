#include<iostream>
#include<stack>

using namespace std;

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
    
    int min() {
        return min_s.top();
    }
};