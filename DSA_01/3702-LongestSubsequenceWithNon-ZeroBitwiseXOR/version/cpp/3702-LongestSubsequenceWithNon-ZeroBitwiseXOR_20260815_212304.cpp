// Last updated: 15/08/2026, 21:23:04
1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int n = nums.size();
5        int totalXor = 0;
6        bool allZero = true;
7
8        for (int x : nums) {
9            totalXor ^= x;
10            if (x > 0) {
11                allZero = false;
12            }
13        }
14
15        if (totalXor > 0) {
16            return n;
17        }
18
19        return allZero ? 0 : n - 1;
20    }
21};