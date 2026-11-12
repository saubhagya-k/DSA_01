// Last updated: 13/11/2026, 01:58:26
1class Solution {
2public:
3    int longestMonotonicSubarray(vector<int>& nums) {
4        int maxLength = 0;
5
6        // Find longest strictly increasing subarray
7        for (int start = 0; start < nums.size(); start++) {
8            int currLength = 1;
9            for (int pos = start + 1; pos < nums.size(); pos++) {
10                // Extend subarray if next element is larger
11                if (nums[pos] > nums[pos - 1]) {
12                    currLength++;
13                } else {
14                    // Break if sequence is not increasing anymore
15                    break;
16                }
17            }
18            maxLength = max(maxLength, currLength);
19        }
20
21        // Find longest strictly decreasing subarray
22        for (int start = 0; start < nums.size(); start++) {
23            int currLength = 1;
24            for (int pos = start + 1; pos < nums.size(); pos++) {
25                // Extend subarray if next element is smaller
26                if (nums[pos] < nums[pos - 1]) {
27                    currLength++;
28                } else {
29                    // Break if sequence is not decreasing anymore
30                    break;
31                }
32            }
33            maxLength = max(maxLength, currLength);
34        }
35
36        return maxLength;  // Return the longer of increasing or decreasing
37                           // sequences
38    }
39};