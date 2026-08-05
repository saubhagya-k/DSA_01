// Last updated: 05/08/2026, 16:54:23
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

int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {

        

        bstsum(root);

        return root;
        
    }

    void bstsum(TreeNode* root){
        if(root == NULL){
            return ;
        }

        bstsum(root->right);

        sum = sum + root->val;

        root->val = sum;

        bstsum(root->left);

        
    }


};