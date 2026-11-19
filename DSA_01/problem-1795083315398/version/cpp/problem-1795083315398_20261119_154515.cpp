// Last updated: 19/11/2026, 15:45:15
1class Solution {
2public:
3    int maxFrequencyElements(vector<int>& nums) {
4
5        unordered_map<int,int>map;
6
7        int final_val = 0;
8
9        int max_freq = INT_MIN;
10
11        for(int num : nums){
12            map[num]++;
13            max_freq = max(max_freq,map[num]);
14        }
15
16
17       for(const auto& [num,freq] : map){
18
19        if(freq == max_freq){
20            final_val+=freq;
21        }
22           
23           
24       }
25
26       return final_val;
27
28
29        
30    }
31};