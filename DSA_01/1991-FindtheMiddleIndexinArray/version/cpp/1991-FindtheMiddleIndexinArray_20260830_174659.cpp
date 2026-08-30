// Last updated: 30/08/2026, 17:46:59
1class Solution {
2public:
3    int findMiddleIndex(vector<int>& nums) {
4        
5        int n = nums.size();
6
7        int total = 0;
8
9        int rightSum = 0;
10        int leftSum = 0;
11
12        for(int i=0;i<n;i++){
13
14            total += nums[i];
15
16        }
17
18        int j=0;
19
20        for(int i=0;i<n;i++){
21
22            rightSum = total-nums[i]-leftSum;
23
24            if(rightSum == leftSum){
25                return i;
26            }
27
28            leftSum += nums[i];
29
30            
31
32        }
33        return -1;
34    }
35};