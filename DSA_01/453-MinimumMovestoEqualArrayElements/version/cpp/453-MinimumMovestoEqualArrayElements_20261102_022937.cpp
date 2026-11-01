// Last updated: 02/11/2026, 02:29:37
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        long long sum = 0;
5        int minNum = nums[0];
6        for (int num : nums) {
7            sum += num;
8            if (num < minNum) {
9                minNum = num;
10            }
11        }
12        return sum - (long long)minNum * nums.size();
13    }
14};
15