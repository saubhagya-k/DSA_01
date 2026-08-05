// Last updated: 05/08/2026, 16:55:49
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        
        stack<Node*> st;
        Node* curr = head;
        
        while (curr) {
            // If current node has a child
            if (curr->child) {
                // If there's a next node, save it for later
                if (curr->next) {
                    st.push(curr->next);
                }
                
                // Connect current node to child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL; // Important: remove child pointer
            }
            
            // If no next node but we have saved nodes in stack
            if (!curr->next && !st.empty()) {
                curr->next = st.top();
                st.top()->prev = curr;
                st.pop();
            }
            
            curr = curr->next;
        }
        
        return head;
    }
};