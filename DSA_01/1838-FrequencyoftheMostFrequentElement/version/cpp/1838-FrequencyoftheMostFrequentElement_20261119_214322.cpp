// Last updated: 19/11/2026, 21:43:22
1#include <vector>
2#include <algorithm>
3
4using namespace std;
5
6class Solution {
7public:
8    int maxFrequency(vector<int>& nums, int k) {
9       
10        sort(nums.begin(), nums.end());
11        int n = nums.size();
12
13      
14        vector<long long> prefix(n + 1, 0);
15        for (int i = 0; i < n; i++) {
16            prefix[i + 1] = prefix[i] + nums[i];
17        }
18
19        int max_freq = 0;
20
21       
22        for (int i = 0; i < n; i++) {
23            int low = 0, high = i;
24            int best_start = i;
25
26            
27            while (low <= high) {
28                int mid = low + (high - low) / 2;
29                
30                long long count = i - mid + 1;
31                long long target_sum = (long long)nums[i] * count;
32                long long original_sum = prefix[i + 1] - prefix[mid];
33
34                if (target_sum - original_sum <= k) {
35                    best_start = mid; 
36                    high = mid - 1;
37                } else {
38                    low = mid + 1;    
39                }
40            }
41
42            max_freq = max(max_freq, i - best_start + 1);
43        }
44
45        return max_freq;
46    }
47};
48