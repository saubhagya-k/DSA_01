// Last updated: 05/08/2026, 16:52:34
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        
        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        
        // Perform BFS to calculate level sums
        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;  // Add current node value to the sum
                
                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            levelSums.push_back(sum);  // Store sum of current level
        }
        
        // If there are fewer than k levels, return -1
        if (levelSums.size() < k) return -1;
        
        // Sort the sums in descending order to find the kth largest
        sort(levelSums.begin(), levelSums.end(), greater<long long>());
        
        return levelSums[k - 1];  // kth largest level sum
    }
};
