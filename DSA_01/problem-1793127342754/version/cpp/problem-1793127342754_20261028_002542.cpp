// Last updated: 28/10/2026, 00:25:42
1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
4
5        int n = nums.size();
6
7       
8        long long  sliding_Count = 0;
9
10        int bad_index = -1;
11        int j = 0;
12
13        while(j<n){
14            if(nums[j]<minK || nums[j]>maxK){
15
16                 bad_index = j;
17               
18            }
19            else{
20               
21
22                sliding_Count += (long long )j-bad_index;
23
24                
25            }
26
27            j++;
28        }
29
30        return sliding_Count;
31        
32    }
33};