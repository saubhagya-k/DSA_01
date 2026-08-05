// Last updated: 05/08/2026, 16:56:51
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
    int height(TreeNode*root){
        if(root==0) return 0;

        int lheight = height(root->left);
        int rheight = height(root->right);

        return max(lheight,rheight)+1;
    }


    int diameterOfBinaryTree(TreeNode* root) {



        if(root == NULL) return NULL;

        int leftDim =  diameterOfBinaryTree(root->left);
        int rightDim =  diameterOfBinaryTree(root->right);

        int curr = height(root->left)+height(root->right);

        return max(curr,max(leftDim,rightDim));

        
        
    }
};