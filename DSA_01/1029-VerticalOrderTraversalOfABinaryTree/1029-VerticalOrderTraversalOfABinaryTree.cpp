// Last updated: 05/08/2026, 16:54:45
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map: col → vector of (row, val)
        map<int, vector<pair<int,int>>> mp;

        // queue: (node, row, col)
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        // Step 1 — BFS
        while(!q.empty()){
            auto [node, row, col] = q.front();
            q.pop();

            // store (row, val) at this col
            mp[col].push_back({row, node->val});

            // push children with updated row and col
            if(node->left)
                q.push({node->left, row+1, col-1});
            if(node->right)
                q.push({node->right, row+1, col+1});
        }

        // Step 2 — collect results
        vector<vector<int>> result;

        for(auto& [col, nodes] : mp){
            // sort by row first, then by value
            sort(nodes.begin(), nodes.end());

            vector<int> colVals;
            for(auto& [row, val] : nodes){
                colVals.push_back(val);
            }
            result.push_back(colVals);
        }

        return result;
    }
};