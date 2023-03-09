// 用两个栈实现队列

// 输入：
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// 输出：
// [null, null, null, 1, 1, false]

// 解释：
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false

#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
        printf("input.size() = %d\n", input.size());
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        check_output_empty();
        int res = output.top();
        output.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        check_output_empty();
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }

    void check_output_empty(){
        if(output.size() == 0)
        {
            int size = input.size();
            for(int i=0; i<size; i++){
                printf("input.top() = %d\n", input.top());
                output.push(input.top());
                input.pop();
            }
        }
    }
};

int main(){
    // MyQueue myQueue = new MyQueue();
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    // myQueue.push(3);
    int a = myQueue.peek(); // return 1
    printf("%d\n", a);
    myQueue.pop(); // return 1, queue is [2]
    bool flag = myQueue.empty(); // return false
    printf("%d\n", flag);
}