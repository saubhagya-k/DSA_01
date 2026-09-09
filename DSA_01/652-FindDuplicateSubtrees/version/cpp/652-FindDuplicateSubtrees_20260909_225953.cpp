// Last updated: 09/09/2026, 22:59:53
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
15string solve(TreeNode* root,unordered_map<string,int>& map,vector<TreeNode*>&final){
16
17    if(root== NULL){
18        return "#";
19
20    }
21
22    string s = "";
23
24    s = to_string(root->val)+","+solve(root->left,map,final)+","+solve(root->right,map,final);
25
26  
27    
28    map[s]++;
29
30    if(map[s]==2){
31
32        final.push_back(root);
33
34    }
35    
36
37    return s;
38    
39
40}
41    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
42
43        if(root == NULL){
44            return {};
45        }
46
47       unordered_map<string,int>map;
48
49       vector<TreeNode*>final;
50
51      solve(root,map,final);
52      
53      return final;
54        
55    }
56};