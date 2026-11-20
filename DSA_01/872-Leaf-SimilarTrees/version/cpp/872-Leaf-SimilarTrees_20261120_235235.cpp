// Last updated: 20/11/2026, 23:52:35
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
15void taliva(TreeNode* root,vector<int>&vec){
16
17    if(root == NULL){
18        return ;
19    }
20
21    taliva(root->left,vec);
22
23    if(root->left == NULL && root->right == NULL){
24      vec.push_back(root->val);
25    }
26
27    taliva(root->right,vec);
28
29}
30    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
31
32        vector<int>vec1;
33        vector<int>vec2;
34
35        taliva(root1,vec1);
36
37        taliva(root2,vec2);
38
39        return vec1 == vec2;
40
41
42        
43    }
44};