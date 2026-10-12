// Last updated: 12/10/2026, 23:31:17
1class Solution {
2public:
3    int maxSum(vector<int>& nums, int k) {
4        const int MOD = 1e9 + 7;
5        vector<int> cnt(30, 0);
6
7        // Count the number of 1 bits at each position
8        for (int num : nums) {
9            for (int i = 0; i < 30; i++) {
10                if (num & (1 << i)) {
11                    cnt[i]++;
12                }
13            }
14        }
15
16        long long res = 0;
17        for (int i = 0; i < k; i++) {
18            long long cur = 0;
19            // Construct the current number from the most significant bit to the
20            // least significant bit
21            for (int j = 29; j >= 0; j--) {
22                if (cnt[j] > 0) {
23                    cur |= (1LL << j);
24                    cnt[j]--;
25                }
26            }
27            res = (res + cur * cur) % MOD;
28        }
29
30        return (int)res;
31    }
32};