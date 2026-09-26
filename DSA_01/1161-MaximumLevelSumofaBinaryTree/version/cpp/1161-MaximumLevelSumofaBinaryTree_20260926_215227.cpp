// Last updated: 26/09/2026, 21:52:27
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
14int storeLevel = 0;
15
16int MaxSum = INT_MIN;
17    int maxLevelSum(TreeNode* root) {
18
19        queue<TreeNode*>q;
20
21        int currentLvl = 1;
22
23        q.push(root);
24
25        
26
27        while(!q.empty()){
28
29            int n = q.size();
30
31            int sum = 0;
32
33            while(n--){
34                TreeNode* temp = q.front();
35                q.pop();
36
37                sum+=temp->val;
38
39                if(temp->left){
40                    q.push(temp->left);
41                }
42
43                if(temp->right){
44                    q.push(temp->right);
45                }
46
47
48                
49
50                
51
52                }
53                if(MaxSum<sum){
54
55                MaxSum = max(MaxSum,sum);
56
57                storeLevel = currentLvl;
58
59        }
60
61            currentLvl++;
62
63        }
64
65        return storeLevel;
66
67
68        
69    }
70};