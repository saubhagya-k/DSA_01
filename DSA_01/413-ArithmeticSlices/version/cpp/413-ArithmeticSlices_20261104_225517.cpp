// Last updated: 04/11/2026, 22:55:17
1class Solution {
2public:
3    int numberOfArithmeticSlices(vector<int>& nums) {
4
5        int totalCount = 0;
6
7        int n = nums.size();
8
9        for(int i=0;i<n-2;i++){
10            int diff = nums[i+1] - nums[i];
11
12            for(int j=i+2;j<n;j++){
13
14                if(nums[j]-nums[j-1] == diff){
15
16                    totalCount++;
17
18                }
19                else{
20                    break;
21                }
22            }
23        }
24
25        return totalCount;
26        
27    }
28};