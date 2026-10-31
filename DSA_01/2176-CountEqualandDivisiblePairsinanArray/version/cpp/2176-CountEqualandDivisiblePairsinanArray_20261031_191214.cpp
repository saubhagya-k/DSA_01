// Last updated: 31/10/2026, 19:12:14
1class Solution {
2public:
3    int countPairs(vector<int>& nums, int k) {
4
5        int n = nums.size();
6
7        int count = 0;
8
9        for(int i=0;i<n;i++){
10            for(int j=i+1;j<n;j++){
11
12                if(nums[i] == nums[j] && (i*j)%k==0){
13
14                    count++;
15
16
17
18                }
19
20            }
21        }
22
23        return count;
24
25        
26        
27    }
28};