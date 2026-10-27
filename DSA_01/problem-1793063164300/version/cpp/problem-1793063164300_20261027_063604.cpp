// Last updated: 27/10/2026, 06:36:04
1class Solution {
2public:
3    long long maximizeSum(vector<int>& nums, int k) {
4
5        vector<int>final;
6        long long totalSum = 0;
7
8        for(int num : nums){
9
10            totalSum+=num;
11
12            string s = to_string(num);
13            sort(s.rbegin(),s.rend());
14
15            int maximizedNum = stoi(s);
16
17            int profit = maximizedNum - num;
18
19            if(profit>0){
20                final.push_back(profit);
21            }
22
23         
24        }
25
26        sort(final.rbegin(),final.rend());
27
28        int total_final = 0;
29
30        int loop = min(k,(int)final.size());
31
32
33        for(int i=0;i<loop;i++){
34
35           totalSum+=final[i];
36            
37        }
38
39        return totalSum;
40
41        
42        
43    }
44};