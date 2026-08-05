// Last updated: 05/08/2026, 16:58:48
#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {
        // Constructor: Queue is implicitly initialized empty
    }
    
    // O(N) time: Push element x onto stack and rotate
    void push(int x) {
        q.push(x);
        
        // Rotate the queue to bring the new element to the front
        int current_size = q.size();
        for (int i = 0; i < current_size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // O(1) time: Removes the element on top of the stack and returns it
    int pop() {
        int top_element = q.front();
        q.pop();
        return top_element;
    }
    
    // O(1) time: Get the top element
    int top() {
        return q.front();
    }
    
    // O(1) time: Returns whether the stack is empty
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
