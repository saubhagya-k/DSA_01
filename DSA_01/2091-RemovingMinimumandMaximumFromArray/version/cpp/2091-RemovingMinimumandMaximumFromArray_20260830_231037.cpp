// Last updated: 30/08/2026, 23:10:37
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int n = nums.size();
5        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
6        int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();
7        int l = min(minidx,
8                    maxidx);  // The smaller value in the most valuable index
9        int r =
10            max(minidx, maxidx);  // The bigger value in the most valuable index
11        return min(
12            {r + 1, n - l, l + 1 + n - r});  // Calculate the minimum number of
13                                             // deletions in three cases
14    }
15};