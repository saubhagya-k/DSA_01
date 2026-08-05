// Last updated: 05/08/2026, 16:58:23
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
    void allPaths(TreeNode* root, string path, vector<string> &ans ){
        // base case: if leaf node
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }

        // go left
        if(root->left){
            allPaths(root->left, path + "->" + to_string(root->left->val), ans);
        }

        // go right
        if(root->right){
            allPaths(root->right, path + "->" + to_string(root->right->val), ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans; // safety check
        string path = to_string(root->val);

        allPaths(root, path, ans);
        return ans;
    }
};
