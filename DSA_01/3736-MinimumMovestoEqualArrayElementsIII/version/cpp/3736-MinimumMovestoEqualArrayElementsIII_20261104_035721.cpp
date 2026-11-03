// Last updated: 04/11/2026, 03:57:21
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int mx = nums[0];
5        for (int x : nums) {
6            mx = max(mx, x);
7        }
8        int ans = 0;
9        for (int x : nums) {
10            ans += mx - x;
11        }
12        return ans;
13    }
14};