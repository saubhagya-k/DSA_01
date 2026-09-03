// Last updated: 03/09/2026, 23:03:54
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int mn = nums1[0];
5        bool hasOdd = false;
6        for (int v : nums1) {
7            if (v < mn) {
8                mn = v;
9            }
10            if (v & 1) {
11                hasOdd = true;
12            }
13        }
14        if (mn & 1) {
15            return true;
16        }
17        return !hasOdd;
18    }
19};