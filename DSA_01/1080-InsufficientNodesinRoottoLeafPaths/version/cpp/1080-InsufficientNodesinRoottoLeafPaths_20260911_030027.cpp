// Last updated: 11/09/2026, 03:00:27
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
15  TreeNode* findSum(TreeNode* root,int& limit,int currentSum){
16    if(root == NULL){
17        return NULL;
18    }
19
20    currentSum+=root->val;
21   
22   if(root->left == NULL && root->right == NULL){
23
24    if(currentSum<limit){
25        return NULL;
26    }
27    return root;
28    }
29
30    root->left = findSum(root->left,limit,currentSum);
31    root->right = findSum(root->right,limit,currentSum);
32
33     if (root->left == NULL && root->right == NULL) {
34            return NULL; 
35        }
36
37    return root;
38
39}
40    TreeNode* sufficientSubset(TreeNode* root, int limit) {
41
42       return findSum(root,limit,0);
43
44
45       
46
47        
48    }
49};