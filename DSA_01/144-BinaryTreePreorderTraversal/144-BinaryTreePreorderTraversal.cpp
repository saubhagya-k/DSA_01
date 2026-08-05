// Last updated: 05/08/2026, 17:00:26
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* node, vector<int>& result) {
        if (!node) return;                // base case
        result.push_back(node->val);      // root
        preorder(node->left, result);     // left
        preorder(node->right, result);    // right
    }
};
;