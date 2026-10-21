// Last updated: 21/10/2026, 23:10:45
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        unordered_map<int, int> map;
5        
6        // Step 1: Count frequencies of each number
7        for (int num : nums) {
8            map[num]++;
9        }
10
11        // Step 2: Move map elements into a vector of pairs
12        vector<pair<int, int>> freqvec(map.begin(), map.end());
13
14        // Step 3: Sort by frequency in descending order
15        sort(freqvec.begin(), freqvec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
16            return a.second > b.second; 
17        });
18
19        // Step 4: Extract the top k elements
20        vector<int> final_res;
21        for (int i = 0; i < k; i++) {
22            final_res.push_back(freqvec[i].first);
23        }
24
25        return final_res;
26    }
27};
28