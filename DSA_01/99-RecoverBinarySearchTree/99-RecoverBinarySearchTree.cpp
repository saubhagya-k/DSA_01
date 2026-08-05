// Last updated: 05/08/2026, 17:01:39
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
   TreeNode*prev = NULL;
   TreeNode*first = NULL;
   TreeNode*second = NULL;



   void InorderTraversal(TreeNode*root){
    if(root==NULL){
        return;
    }

    InorderTraversal(root->left);

    if(prev !=NULL && prev->val >root->val){
        if(first == NULL){
            first=prev;
        }
        second = root;
    }

    prev = root;
    InorderTraversal(root->right);

   }



    void recoverTree(TreeNode* root) {

        InorderTraversal(root);

        int temp = second->val;

        second->val = first->val;

        first->val = temp;


        
    }
};