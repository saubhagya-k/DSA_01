// Last updated: 29/09/2026, 21:26:38
1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, int k) {
4
5        int max_ele = 0;
6        for(int i=0;i<nums.size();i++){
7            max_ele = max(max_ele,nums[i]);
8        }
9
10        int start = 0,end=0,count=0,n=nums.size();
11        long long total=0;
12
13        while(end<n){
14
15            if(nums[end] == max_ele){
16                count++;
17
18                while(count == k){
19
20                    total += n-end;
21
22                    if(nums[start] == max_ele){
23                        count--;
24                    }
25                    start++;
26
27                }
28            }
29
30
31
32
33
34            end++;
35            
36
37        }
38        return total;
39        
40    }
41};