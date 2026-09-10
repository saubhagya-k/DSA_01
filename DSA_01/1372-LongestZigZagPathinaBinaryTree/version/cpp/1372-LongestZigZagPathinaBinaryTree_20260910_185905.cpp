// Last updated: 10/09/2026, 18:59:05
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
14int maxCount = 0;
15
16void solve(TreeNode* root,int steps,bool goleft){
17    if(root == NULL){
18        return;
19    }
20
21    maxCount = max(maxCount,steps);
22
23    if(goleft == true){
24        solve(root->left,steps+1,false);
25        solve(root->right,1,true);
26    }
27    else{
28        solve(root->right,steps+1,true);
29        solve(root->left,1,false);
30        
31    }
32}
33
34    int longestZigZag(TreeNode* root) {
35
36        int steps = 0;
37
38        solve(root,steps,true);
39        
40
41
42        return maxCount;
43
44
45        
46    }
47};