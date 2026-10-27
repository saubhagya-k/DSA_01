// Last updated: 28/10/2026, 02:35:05
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
15int inorder(TreeNode* root,int low,int high){
16
17    if (root == nullptr) {
18            return 0;
19        }
20
21    if(root->val>=low && root->val<=high){
22        return root->val+inorder(root->left,low,high)+inorder(root->right,low,high);
23    }
24
25    if(root->val<low){
26        return inorder(root->right,low,high);
27    }
28    if(root->val>high){
29        return inorder(root->left,low,high);
30    }
31
32    return -1;
33}
34
35
36    int rangeSumBST(TreeNode* root, int low, int high) {
37
38
39        if(root == NULL){
40            return 0;
41        }
42
43        return inorder(root,low,high);
44        
45    }
46};