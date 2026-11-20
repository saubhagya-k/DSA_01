// Last updated: 21/11/2026, 01:07:48
1class Solution {
2public:
3    int maxSelectedElements(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        unordered_map<int, int> dp;
6        int ans = 0;
7        for (int x : nums) {
8            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
9            dp[x] = max(dp[x], dp[x - 1] + 1);
10            ans = max(ans, max(dp[x], dp[x + 1]));
11        }
12        return ans;
13    }
14};