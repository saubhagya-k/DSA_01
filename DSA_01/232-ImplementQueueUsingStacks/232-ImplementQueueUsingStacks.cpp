// Last updated: 05/08/2026, 16:58:44
#include <stack>

class MyQueue {
private:
    // s1 handles incoming items, s2 stores items in reversed (FIFO) order
    std::stack<int> s1;
    std::stack<int> s2;

    // Helper method to move elements from s1 to s2 when s2 is empty
    void fill_s2_if_empty() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        fill_s2_if_empty();
        int front_element = s2.top();
        s2.pop();
        return front_element;
    }
    
    int peek() {
        fill_s2_if_empty();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
