// Last updated: 15/11/2026, 19:37:22
1class Solution {
2private:
3    bool foundP = false;
4    bool foundQ = false;
5
6    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
7        // 1. Base Case: ONLY return on nullptr
8        if (root == nullptr) {
9            return nullptr;
10        }
11
12        // 2. Always traverse left and right first (Post-order)
13        TreeNode* left = dfs(root->left, p, q);
14        TreeNode* right = dfs(root->right, p, q);
15
16        // 3. Check current node AFTER children so we don't miss anything
17        if (root == p) {
18            foundP = true;
19            return root;
20        }
21        if (root == q) {
22            foundQ = true;
23            return root;
24        }
25
26        // 4. Standard LCA merge logic
27        if (left != nullptr && right != nullptr) {
28            return root; // p and q are in different subtrees
29        }
30        
31        return (left != nullptr) ? left : right;
32    }
33
34public:
35    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
36        TreeNode* ans = dfs(root, p, q);
37        
38        // Only return the LCA if BOTH nodes were actually found in the tree
39        return (foundP && foundQ) ? ans : nullptr;
40    }
41};
42