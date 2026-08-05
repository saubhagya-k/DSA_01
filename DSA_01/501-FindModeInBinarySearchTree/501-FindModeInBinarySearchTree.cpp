// Last updated: 05/08/2026, 16:57:07
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

unordered_map<int,int>map;
vector<int>final;

int maxfre = 0;

    vector<int> findMode(TreeNode* root) {

        if(root == NULL){
            return{};
        }

        modebst(root);

        for(auto& pair:map){
           if(pair.second == maxfre){
            final.push_back(pair.first);
           }
        }

        return final;
}

void modebst(TreeNode* root){
     if (root == NULL) return;

    modebst(root->left);

   map[root->val]++;

   maxfre = max(maxfre,map[root->val]);

   modebst(root->right);

   
}


};