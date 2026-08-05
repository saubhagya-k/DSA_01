// Last updated: 05/08/2026, 16:53:18
class BrowserHistory {
public:
    struct Node {
        string data;
        Node* prev;
        Node* next;
        Node(string d) {
            data = d;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    Node* current;

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;      // Remove forward history
        newNode->prev = current;
        current = newNode;
    }
    
    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->data;
    }
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */