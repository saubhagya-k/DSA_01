// Last updated: 16/09/2026, 23:55:27
1const int MOD = 1000000007;
2
3class Solution {
4public:
5    int numberOfSets(int n, int k) {
6        vector<int> dp(n), prefixSums(n + 1);
7        for (int j = 0; j < n; j++) {
8            dp[j] = 1;
9            prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
10        }
11        for (int i = 1; i <= k; i++) {
12            dp[0] = 0;
13            for (int j = 1; j < n; j++) {
14                dp[j] = (dp[j - 1] + prefixSums[j]) % MOD;
15            }
16            for (int j = 0; j < n; j++) {
17                prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
18            }
19        }
20        return dp[n - 1];
21    }
22};