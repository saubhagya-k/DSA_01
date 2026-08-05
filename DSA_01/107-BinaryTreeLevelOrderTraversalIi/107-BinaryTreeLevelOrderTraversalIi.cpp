// Last updated: 05/08/2026, 17:01:18
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>>result;

        if(root == NULL ) return result;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();

            vector<int>final;

            for(int i=0;i<size;i++){
                TreeNode*node = q.front();
                final.push_back(node->val);
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);


                
            }
            result.push_back(final);

        }
        reverse(result.begin(), result.end());
        
        return result;

        
    }
};