// Last updated: 08/09/2026, 19:05:04
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14
15unordered_map<int,int>map;
16int maxD = 0;
17
18void freq(TreeNode* root,int d){
19    if(root == NULL){
20        return;
21    }
22
23    maxD = max(maxD,d);
24
25    map[root->val] = d;
26
27    freq(root->left,d+1);
28    freq(root->right,d+1);
29
30}
31
32TreeNode*LCA(TreeNode* root){
33
34    if(root == NULL || map[root->val]==maxD){
35        return root;
36    }
37
38    TreeNode*l = LCA(root->left);
39    TreeNode*r = LCA(root->right);
40
41    if(l && r){
42        return root;
43    }
44
45    if(r==NULL){
46        return l;
47    }
48    
49    return r;
50    
51}
52    TreeNode* lcaDeepestLeaves(TreeNode* root) {
53
54        freq(root,0);
55
56        return LCA(root);
57
58
59
60
61        
62    }
63};