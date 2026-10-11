// Last updated: 11/10/2026, 23:10:41
1class Solution {
2public:
3    int sumOfSquares(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int sum = 0;
8
9        for(int i=1;i<=n;i++){
10
11            if(n%i==0){
12                sum+=nums[i-1]*nums[i-1];
13            }
14
15        }
16
17        return sum;
18        
19    }
20};