// Last updated: 26/09/2026, 16:45:44
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
14typedef unsigned long long ll;
15    int widthOfBinaryTree(TreeNode* root) {
16
17        queue<pair<TreeNode*, ll >>que;
18        que.push({root,0});
19
20        ll maxWidth = 0;
21
22        while(!que.empty()){
23            ll L = que.front().second;
24            ll R = que.back().second;
25            
26            maxWidth = max(maxWidth,R-L+1);
27            
28            ll n = que.size();
29            while(n--){
30                TreeNode* curr = que.front().first;
31              ll idx = que.front().second;
32                que.pop();
33
34                if(curr->left){
35                    que.push({curr->left,2*idx+1});
36                }
37                if(curr->right){
38                    que.push({curr->right,2*idx+2});
39                }
40            } 
41            
42                   }
43
44
45                   return maxWidth;
46        
47    }
48};