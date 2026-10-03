// Last updated: 03/10/2026, 17:20:11
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24    unordered_map<Node*, Node*> mp;
25
26    void DFS(Node* node, Node* clone_node) {
27        for (Node* n : node->neighbors) {
28            if (mp.find(n) == mp.end()) {
29                Node* clone = new Node(n->val);
30                mp[n] = clone;
31                clone_node->neighbors.push_back(clone);
32                
33                // Fixed: Passed only 2 arguments to match definition
34                DFS(n, clone); 
35            }
36            else {
37                // Fixed: Corrected the typo from > to ->
38                clone_node->neighbors.push_back(mp[n]);
39            }
40        }
41    }
42
43    Node* cloneGraph(Node* node) {
44        if (node == NULL) {
45            return NULL;
46        }
47        
48        Node* clone_node = new Node(node->val);
49        mp[node] = clone_node;
50
51        // Fixed: Removed 'mp' from arguments since it's a class member
52        DFS(node, clone_node);
53
54        // Fixed: Added missing return statement
55        return clone_node;
56    }
57};
58