// Last updated: 12/11/2026, 14:04:38
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Solution {
12public:
13    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
14
15        if(root == NULL){
16            return NULL;
17        }
18
19        int currentValue = root->val;
20
21        if(currentValue< p->val  && currentValue< q->val){
22            return lowestCommonAncestor(root->right,p,q);
23        }
24        else if(currentValue>p->val && currentValue>q->val){
25            return lowestCommonAncestor(root->left,p,q);
26        }
27        else
28        return root;
29
30
31        
32    }
33};