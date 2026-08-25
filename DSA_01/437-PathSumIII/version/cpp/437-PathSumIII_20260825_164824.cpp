// Last updated: 25/08/2026, 16:48:24
1class Solution {
2public:
3    int total = 0;
4
5    int pathSum(TreeNode* root, int sum) {
6        if (root == NULL) {
7            return 0;
8        }
9
10        // Use long long to handle LeetCode integer overflows
11        unordered_map<long long, int> map;
12        map[0] = 1; 
13
14        helper(root, sum, map, 0);
15        return total;
16    }
17
18    void helper(TreeNode* root, int sum, unordered_map<long long, int>& map, long long current) {
19        if (root == NULL) {
20            return;
21        }
22
23        current += root->val;
24
25        if (map.find(current - sum) != map.end()) {
26            // FIX: Add the actual number of times this prefix sum has appeared
27            total += map[current - sum]; 
28        }
29
30        map[current]++;
31
32        helper(root->left, sum, map, current);
33        helper(root->right, sum, map, current);
34
35        map[current]--;
36        if (map[current] == 0) {
37            map.erase(current);
38        }
39    }
40};
41