// Last updated: 21/11/2026, 00:52:30
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
15int finalval = 0;
16    int findTilt(TreeNode* root) {
17
18        check(root);
19
20        return finalval;
21    }
22
23    int check(TreeNode* node){
24        if(node == NULL){
25            return 0;
26        }
27
28        int leftTree = check(node->left);
29        int rightTree = check(node->right);
30
31        finalval+=abs(leftTree-rightTree);
32
33        return leftTree+rightTree+node->val;
34    }
35};