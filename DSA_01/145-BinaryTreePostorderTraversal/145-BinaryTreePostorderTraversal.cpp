// Last updated: 05/08/2026, 17:00:24
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
    vector<int> postorderTraversal(TreeNode* root) {
          vector<int>result;
          post(root,result);
          return result;
        
    };
    void post(TreeNode*node,vector<int>&result){
        if(!node) return;

        post(node->left,result);
        post(node->right,result);
        result.push_back(node->val);
    }
};