// Last updated: 31/10/2026, 12:21:08
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
14int mindiff = INT_MAX;
15
16void inorder(TreeNode* root, TreeNode*&prev){
17
18    if(root == NULL){
19        return ;
20    }
21
22    inorder(root->left,prev);
23
24    if(prev != NULL){
25        mindiff = min(mindiff,abs(root->val - prev->val));
26    }
27
28    prev = root;
29
30    inorder(root->right,prev);
31
32}
33    int getMinimumDifference(TreeNode* root) {
34
35        TreeNode*prev = NULL;
36
37        inorder(root,prev);
38
39        return mindiff;
40
41        
42    }
43};