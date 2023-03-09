// 两个栈实现队列

#include<iostream>
#include<stack>

using namespace std;

class CQueue {
stack<int> s1,s2;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(!s2.empty())
        {
            int a=s2.top();
            s2.pop();
            return a;
        }
        if(s1.empty())  return -1;
        while(!s1.empty())
          {
                s2.push(s1.top());
                s1.pop();
                
          }
          int b = s2.top();
          s2.pop();
          return b;
    }
};