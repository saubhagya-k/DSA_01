// Last updated: 06/10/2026, 20:16:28
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        int n = nums.size();
5        unordered_set<int> set;
6
7        for (int x : nums) {
8            set.insert(x);
9        }
10
11        int maxi = 0;
12
13        for (int i = 0; i < n; i++) {
14            // Only start if it's the beginning of a sequence
15            if (set.find(nums[i] - 1) == set.end()) {
16                int current_val = nums[i];
17                int count = 0;
18
19                // Erasing visited elements guarantees O(N) execution time 
20                // and avoids worst-case hash collision overhead.
21                while (set.find(current_val) != set.end()) {
22                    count++;
23                    set.erase(current_val); // Removes it so it's never processed again
24                    current_val++;
25                }
26
27                maxi = max(maxi, count);
28            }
29        }
30
31        return maxi;
32    }
33};
34