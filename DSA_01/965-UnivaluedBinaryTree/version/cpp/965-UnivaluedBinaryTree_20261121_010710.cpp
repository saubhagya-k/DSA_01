// Last updated: 21/11/2026, 01:07:10
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
14bool finalcheck(TreeNode* root,int target){
15
16    if(root==NULL) return true;
17
18   
19   if(root->val != target){
20    return false;
21    
22   }
23   
24
25
26   return finalcheck(root->left, target) && finalcheck(root->right, target);
27
28};
29    bool isUnivalTree(TreeNode* root) {
30        if(root == NULL){
31            return true;
32
33        }
34
35        return finalcheck(root,root->val);
36    }
37};