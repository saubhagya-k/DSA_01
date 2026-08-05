// Last updated: 05/08/2026, 17:00:14
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        class Node {
        public:
            int data;
            Node* next;
            Node(int val) {
                data = val;
                next = nullptr;
            }
        };

        class Stack {
        public:
            Node* top = nullptr;
            
            void push(int val) {
                Node* temp = new Node(val);
                temp->next = top;
                top = temp;
            }
            
            int pop() {
                if (!top) return 0;
                int val = top->data;
                Node* temp = top;
                top = top->next;
                delete temp;
                return val;
            }

            ~Stack() { 
                while (top) {
                    pop();
                }
            }
        };

        Stack st;

        
        for (const string& token : tokens) {
           
            if (token == "+" || token == "-" || token == "*" || token == "/") {
              
                int b = st.pop();
                int a = st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // C++ division naturally truncates toward zero
            } 
            else {
                // If it's a number (positive or negative), convert and push
                st.push(stoi(token));
            }
        }

        // The final remaining value on the stack is the total expression result
        return st.pop();
    }
};
