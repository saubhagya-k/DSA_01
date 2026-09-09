// Last updated: 09/09/2026, 18:41:41
// nice question
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
14TreeNode*solve(int prestart,int poststart, int preend,vector<int>& preorder, vector<int>& postorder){
15
16    if(prestart>preend){
17        return NULL;
18    }
19   
20
21    TreeNode* root = new TreeNode(preorder[prestart]);
22
23     if(prestart == preend){
24        return root;
25    }
26    int nextNode = preorder[prestart+1];  // this is root of left sub tree
27
28    int j = poststart;
29
30    while(postorder[j]!=nextNode){
31        j++;
32    }
33
34    int num = j-poststart+1;
35
36    root->left = solve(prestart+1,poststart,prestart+num,preorder,postorder);
37
38    root->right = solve(prestart+num+1,j+1,preend,preorder,postorder);
39
40
41
42    return root;
43
44
45
46}
47    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
48
49        int n = preorder.size();
50
51        return solve(0,0,n-1,preorder,postorder);
52        
53    }
54};