// Last updated: 10/09/2026, 23:33:00
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
15int final = 0;
16
17void solve(TreeNode* root){
18
19    if(root == NULL){
20        return;
21    }
22
23    int count = 0;
24
25    int sum = findSum(root,count);
26
27    if(root->val == sum/count){
28
29        final++;
30
31    }
32
33    solve(root->left);
34    solve(root->right);
35};
36
37int findSum(TreeNode* root,int& count){
38    if(root == NULL){
39        return 0;
40    }
41    count++;
42
43    int lsum = findSum(root->left,count);
44    int rsum = findSum(root->right,count);
45
46    return root->val+lsum+rsum;
47
48};
49
50
51
52    int averageOfSubtree(TreeNode* root) {
53
54        
55
56        solve(root);
57
58
59        return final;
60        
61    }
62};
63