// Last updated: 31/10/2026, 18:06:03
1class Solution {
2public:
3    int countKDifference(vector<int>& nums, int k) {
4
5        int n = nums.size();
6        int count = 0;
7
8        for(int i=0;i<n;i++){
9            for(int j=i+1;j<n;j++){
10
11                if(abs(nums[i]-nums[j]) == k){
12
13                    count++;
14
15                }
16            }
17        }
18
19        return count;
20        
21    }
22};