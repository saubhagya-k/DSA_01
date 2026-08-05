// Last updated: 05/08/2026, 17:01:04
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;   // stores all valid paths
    vector<int> current;          // current path being explored

    void dfs(TreeNode* node, int remaining) {
        if (node == NULL) return;

        // 1. Choose: add current node to path
        current.push_back(node->val);
        remaining -= node->val;

        // 2. Check: if leaf node AND remaining sum == 0, valid path found
        if (node->left == NULL && node->right == NULL && remaining == 0) {
            result.push_back(current);  // save a copy of current path
        }

        // 3. Explore: go deeper left and right
        dfs(node->left, remaining);
        dfs(node->right, remaining);

        // 4. Backtrack: remove current node before going back up
        current.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};