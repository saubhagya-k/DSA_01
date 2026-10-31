// Last updated: 01/11/2026, 00:29:46
1class Solution {
2public:
3    int countNicePairs(vector<int>& nums) {
4        int n = nums.size();
5        long long count = 0; // Changed to long long to prevent overflow
6        int MOD = 1e9 + 7;   // Added LeetCode modulo constraint
7
8        for(int i = 0; i < n; i++){
9            int temp = nums[i]; // Keep a backup copy of the original number
10            int rev_num = 0;    // Reset the reversed number for each element
11
12            while(temp > 0){
13                rev_num = rev_num * 10 + (temp % 10);
14                temp /= 10;
15            }
16            
17            // Fix: Use the raw original number minus the direct variable `rev_num`
18            nums[i] = nums[i] - rev_num; 
19        }
20
21        unordered_map<int, int> map;
22        for(int i = 0; i < n; i++){
23            if(map.find(nums[i]) != map.end()){
24                count += map[nums[i]];
25            }
26            map[nums[i]]++;
27        }
28
29        return count % MOD; // Return using modulo
30    }
31};
32