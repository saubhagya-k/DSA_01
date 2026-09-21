// Last updated: 22/09/2026, 01:44:34
1class Solution {
2public:
3    vector<long long> resultArray(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<long long> result(k);
6        vector<long long> dp(k);  // Initial state: no elements have been
7                                  // processed, so no non-empty subarray exists.
8
9        for (int i = 0; i < n; i++) {
10            vector<long long> ndp(k);  // Current-layer state (rolling array).
11
12            ndp[nums[i] % k]++;
13
14            for (int r = 0; r < k; r++) {
15                ndp[(long long)r * nums[i] % k] += dp[r];
16            }
17
18            dp = move(ndp);  // Update the state.
19
20            // Accumulate the answer.
21            for (int r = 0; r < k; r++) {
22                result[r] += dp[r];
23            }
24        }
25
26        return result;
27    }
28};