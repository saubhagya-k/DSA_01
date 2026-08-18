// Last updated: 19/08/2026, 01:15:52
1class Solution {
2public:
3    int findNumberOfLIS(vector<int>& nums) {
4
5        int n = nums.size();
6
7        vector<int>t(n,1);   //LIS ending at i
8        vector<int>count(n,1);
9
10
11        for(int i=0;i<n;i++){
12            for(int j=0;j<i;j++){
13
14                if(nums[j]<nums[i]){
15                    if(t[j]+1 == t[i]){
16                        count[i] += count[j];
17                    }
18                    else if(t[j]+1>t[i]){
19                        t[i] = t[j] + 1;
20
21                        count[i] = count[j];
22
23                    }
24                }
25
26            }
27        }
28
29        int maxval = *max_element(begin(t),end(t));
30        int result = 0;
31        for(int i=0;i<n;i++){
32            if(t[i]== maxval){
33                result += count[i];
34            }
35        }
36
37        return result;
38 
39
40        
41    }
42};