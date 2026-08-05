// Last updated: 05/08/2026, 17:01:46
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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>final;

        real(root,final);
        return final;


    };



        void real(TreeNode* root, vector<int>&final){

        if(root == NULL){
            return ;
        }

        real(root->left,final);
        final.push_back(root->val);
        real(root->right,final);


        

        
    }
};