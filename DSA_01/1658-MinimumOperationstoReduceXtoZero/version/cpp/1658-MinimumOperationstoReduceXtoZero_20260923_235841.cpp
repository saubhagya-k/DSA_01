// Last updated: 23/09/2026, 23:58:41
1#include <vector>
2#include <numeric>
3#include <algorithm>
4
5class Solution {
6public:
7    int minOperations(std::vector<int>& nums, int x) {
8        // Calculate the total sum of the array
9        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
10        
11        // The target sum for our middle subarray
12        int target = total_sum - x;
13        
14        // If target is negative, it's impossible to reduce x to 0
15        if (target < 0) return -1;
16        
17        // If target is 0, we must remove all elements
18        if (target == 0) return nums.size();
19        
20        int current_sum = 0;
21        int max_len = -1;
22        int left = 0;
23        
24        // Sliding window to find the longest subarray that sums to target
25        for (int right = 0; right < nums.size(); ++right) {
26            current_sum += nums[right];
27            
28            // Shrink the window from the left if the current sum exceeds target
29            while (current_sum > target && left <= right) {
30                current_sum -= nums[left];
31                left++;
32            }
33            
34            // If we find a valid subarray, update the maximum length
35            if (current_sum == target) {
36                max_len = std::max(max_len, right - left + 1);
37            }
38        }
39        
40        // If max_len was updated, return remaining elements; otherwise return -1
41        return (max_len == -1) ? -1 : nums.size() - max_len;
42    }
43};
44