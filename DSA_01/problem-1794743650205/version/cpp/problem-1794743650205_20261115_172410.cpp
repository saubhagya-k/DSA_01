// Last updated: 15/11/2026, 17:24:10
1class Solution {
2public:
3    int countConsistent(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int count = 0;
8
9        for(int i=0;i<n;i++){
10            int curr_and = nums[i];
11            int curr_min = nums[i];
12
13            for(int j=i;j<n;j++){
14                curr_and &= nums[j];
15                curr_min = min(curr_min,nums[j]);
16
17                if(curr_min == curr_and){
18                    count++;
19                }
20            }
21
22            
23        }
24
25        return count;
26        
27    }
28};