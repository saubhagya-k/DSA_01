// Last updated: 18/08/2026, 23:34:18
1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4        int n = nums.size();
5        if (n == k) {
6            return *max_element(nums.begin(), nums.end());
7        }
8        int count[51] = {0};
9        for (int x : nums) {
10            count[x]++;
11        }
12        if (k == 1) {
13            for (int i = 50; i >= 0; --i) {
14                if (count[i] == 1) {
15                    return i;
16                }
17            }
18            return -1;
19        }
20        int res = -1;
21        if (count[nums[0]] == 1) {
22            res = max(res, nums[0]);
23        }
24        if (count[nums.back()] == 1) {
25            res = max(res, nums.back());
26        }
27        return res;
28    }
29};