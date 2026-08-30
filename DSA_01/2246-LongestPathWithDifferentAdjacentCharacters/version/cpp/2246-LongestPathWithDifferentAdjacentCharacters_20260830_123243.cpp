// Last updated: 30/08/2026, 12:32:43
1
2class Solution {
3public:
4
5int maxCount = 0;
6
7int dfs(TreeNode* node){
8
9    if(node == NULL){
10        return 0;
11    }
12
13    int leftChild = dfs(node->left);
14    int rightChild = dfs(node->right);
15
16    int leftCount = 0;
17    int rightCount = 0;
18
19    if(node->left!=NULL && node->left->val == node->val){
20        leftCount = leftChild+1;
21    }
22
23      if(node->right!=NULL && node->right->val == node->val){
24        rightCount = rightChild+1;
25    }
26
27    maxCount = max(maxCount,leftCount+rightCount);
28
29  return max(leftCount, rightCount);
30
31
32}
33    int longestUnivaluePath(TreeNode* root) {
34
35        if(root == NULL){
36            return 0;
37        }
38
39      dfs(root);
40
41        return maxCount;
42        
43    }
44};