// Last updated: 20/10/2026, 19:20:42
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
14    int minDepth(TreeNode* root) {
15
16        if(root == NULL){
17            return 0;
18        }
19
20        int leftsubTree = minDepth(root->left);
21        int rightsubTree = minDepth(root->right);
22
23        if(leftsubTree == 0){
24            return rightsubTree+1;
25        }
26        if(rightsubTree == 0){
27
28            return leftsubTree+1;
29
30        }
31        
32        return min(leftsubTree,rightsubTree)+1;
33    }
34};