// Last updated: 05/08/2026, 16:59:20
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
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL) return{};

        map<int,int>m;

        queue<pair<TreeNode*,int>>q;

        q.push({root,0});


        while(!q.empty()){
            TreeNode*curr = q.front().first;
            int currPos = q.front().second;

            q.pop();

            m[currPos] = curr->val;

            if(curr->left != NULL){
                q.push({curr->left,currPos+1});
            }

            if(curr->right != NULL){
                q.push({curr->right,currPos+1});
            }
        }

        vector<int>result;

        for(auto& [row,val] :m){
            result.push_back(val);
        }

        return result;

        

        
        
    }
};