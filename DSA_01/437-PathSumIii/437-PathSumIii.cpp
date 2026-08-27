// Last updated: 27/08/2026, 12:54:10
class Solution {
public:
    int total = 0;

    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }

        // Use long long to handle LeetCode integer overflows
        unordered_map<long long, int> map;
        map[0] = 1; 

        helper(root, sum, map, 0);
        return total;
    }

    void helper(TreeNode* root, int sum, unordered_map<long long, int>& map, long long current) {
        if (root == NULL) {
            return;
        }

        current += root->val;

        if (map.find(current - sum) != map.end()) {
            // FIX: Add the actual number of times this prefix sum has appeared
            total += map[current - sum]; 
        }

        map[current]++;

        helper(root->left, sum, map, current);
        helper(root->right, sum, map, current);

        map[current]--;
        if (map[current] == 0) {
            map.erase(current);
        }
    }
};
