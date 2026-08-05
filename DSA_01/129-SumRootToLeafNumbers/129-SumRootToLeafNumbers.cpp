// Last updated: 05/08/2026, 17:00:40
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
    int sumNumbers(TreeNode* root) {

        return helper(root,0);
        
    }
    int helper(TreeNode*root,int currNode){
        if(root ==NULL){
            return 0;
        }

        currNode = currNode*10+root->val;

        if(root->left ==NULL && root->right== NULL){
            return currNode;
        }

        int left = helper(root->left,currNode);
        int right = helper(root->right,currNode);

        return left+right;
    }
};