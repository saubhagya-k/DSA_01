// Last updated: 30/08/2026, 23:09:38
1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, int k) {
4        int maxElement = *max_element(nums.begin(), nums.end());
5        long long ans = 0, start = 0;
6        int maxElementsInWindow = 0;
7
8        for (int end = 0; end < nums.size(); end++) {
9            if (nums[end] == maxElement) {
10                maxElementsInWindow++;
11            }
12            while (maxElementsInWindow == k) {
13                if (nums[start] == maxElement) {
14                    maxElementsInWindow--;
15                }
16                start++;
17            }
18            ans += start;
19        }
20        return ans;
21    }
22};