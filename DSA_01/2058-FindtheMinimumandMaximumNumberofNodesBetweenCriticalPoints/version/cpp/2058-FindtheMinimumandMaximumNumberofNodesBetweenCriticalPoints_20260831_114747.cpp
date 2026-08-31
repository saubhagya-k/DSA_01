// Last updated: 31/08/2026, 11:47:47
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int mini = INT_MAX;
8        int minInd = 0;
9
10        int maxi = INT_MIN;
11        int maxInd = 0;
12
13        for(int i=0;i<n;i++){
14
15            if(nums[i]<mini){
16                mini = nums[i];
17                minInd = i;
18            }
19            
20        }
21
22        for(int i=0;i<n;i++){
23
24            if(nums[i]>maxi){
25                maxi = nums[i];
26                maxInd = i;
27            }
28
29        }
30
31        int leftIndex = min(minInd,maxInd);
32        int rightIndex = max(minInd,maxInd);
33
34
35        return min({leftIndex+1+n-rightIndex,rightIndex+1,n-leftIndex});
36        
37    }
38};