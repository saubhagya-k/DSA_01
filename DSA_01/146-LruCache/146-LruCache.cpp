// Last updated: 05/08/2026, 17:00:21
#include <unordered_map>

class LRUCache {
private:
    
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cacheMap;
    
    
    Node* head;
    Node* tail;

   
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
   
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        Node* node = cacheMap[key];
        moveToHead(node); 
        return node->val;
    }
    
    
    void put(int key, int value) {
        
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->val = value;
            moveToHead(node);
            return;
        }

        
        if (cacheMap.size() == capacity) {
            Node* lruNode = tail->prev; 
            cacheMap.erase(lruNode->key);
            removeNode(lruNode);
            delete lruNode; 
        }

        
        Node* newNode = new Node(key, value);
        cacheMap[key] = newNode;
        addNode(newNode);
    }
    
    
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
