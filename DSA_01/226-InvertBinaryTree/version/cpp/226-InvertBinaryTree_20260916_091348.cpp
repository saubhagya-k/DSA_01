// Last updated: 16/09/2026, 09:13:48
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
14    TreeNode* invertTree(TreeNode* root) {
15
16        queue<TreeNode*>q;
17       
18
19        if(root == NULL){
20            return NULL;
21        }
22
23        q.push(root);
24
25        while(!q.empty()){
26            TreeNode* node = q.front();
27
28            q.pop();
29
30            TreeNode* temp = node->left;
31
32            node->left = node->right;
33
34            node->right = temp;
35
36            
37
38           
39
40            if(node->left!=NULL){
41                q.push(node->left);
42            }
43
44            if(node->right!=NULL){
45                q.push(node->right);
46            }
47
48
49        }
50
51        return root;
52        
53    }
54};