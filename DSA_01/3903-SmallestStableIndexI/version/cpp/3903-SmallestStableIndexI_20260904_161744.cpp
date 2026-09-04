// Last updated: 04/09/2026, 16:17:44
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        for (int i = 0; i < n; ++i) {
6            int maxValue = nums[i], minValue = nums[i];
7            for (int j = 0; j < i; ++j) {
8                maxValue = max(maxValue, nums[j]);
9            }
10            for (int j = i + 1; j < n; ++j) {
11                minValue = min(minValue, nums[j]);
12            }
13            if (maxValue - minValue <= k) {
14                return i;
15            }
16        }
17        return -1;
18    }
19};