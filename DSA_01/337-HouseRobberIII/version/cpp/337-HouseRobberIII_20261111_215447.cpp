// Last updated: 11/11/2026, 21:54:47
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
15vector<int> dfs(TreeNode* node){
16    if(node == nullptr){
17        return {0, 0};
18    }
19
20        vector<int>left = dfs(node->left);
21        vector<int>right = dfs(node->right);
22
23        int robCurrent = node->val + left[0] + right[0];
24
25        int skipCurrent = max(left[0],left[1]) + max(right[0],right[1]);
26
27        return {skipCurrent,robCurrent};
28    }
29
30    int rob(TreeNode* root) {
31
32        vector<int> result = dfs(root);
33
34        return max(result[0], result[1]);
35        
36    }
37};