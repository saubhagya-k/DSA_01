// Last updated: 20/10/2026, 23:06:28
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> children;
7
8    Node() {}
9
10    Node(int _val) {
11        val = _val;
12    }
13
14    Node(int _val, vector<Node*> _children) {
15        val = _val;
16        children = _children;
17    }
18};
19*/
20
21class Solution {
22public:
23    int maxDepth(Node* root) {
24
25        if(root == NULL){
26            return 0;
27        }
28
29        int maxChildDepth = 0;
30
31        for (Node* child : root->children) {
32            int currentChildDepth = maxDepth(child);
33            maxChildDepth = max(maxChildDepth, currentChildDepth);
34        }
35
36        return maxChildDepth + 1;
37        
38    }
39};