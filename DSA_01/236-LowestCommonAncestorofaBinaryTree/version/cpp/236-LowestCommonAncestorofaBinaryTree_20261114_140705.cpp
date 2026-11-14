// Last updated: 14/11/2026, 14:07:05
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13
14        if(root == NULL || p == root || q == root){
15            return root;
16        }
17
18        TreeNode* leftOne = lowestCommonAncestor(root->left,p,q);
19
20        TreeNode* rightOne = lowestCommonAncestor(root->right,p,q);
21
22        if(leftOne == NULL){
23            return rightOne;
24        }
25
26        if(rightOne == NULL){
27            return leftOne;
28        }
29
30        return root;
31
32
33        
34    }
35};