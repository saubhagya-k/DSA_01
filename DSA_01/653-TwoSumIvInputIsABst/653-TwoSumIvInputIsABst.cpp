// Last updated: 05/08/2026, 16:56:11
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

     unordered_set<int>us;

    bool dfs(TreeNode*root, int k){
        if(root==NULL) return false;

        if(us.count(k-root->val)){
            return true;

        }
        us.insert(root->val);

        return dfs(root->left,k)||dfs(root->right,k);

       
    }


    bool findTarget(TreeNode* root, int k) {
        return dfs(root,k);
        
    }
};