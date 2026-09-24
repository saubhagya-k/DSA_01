// Last updated: 24/09/2026, 09:25:02
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int num = 0;
8
9        int sum = 0;
10
11
12
13        
14
15        for(int i=0;i<n;i++){
16
17            int temp = nums[i];
18
19            sum = 0;
20           
21            while(temp>0){
22                int num = temp%10;
23
24                sum+=num;
25
26                temp = temp/10;
27
28                
29            }
30            if(sum == i){
31                    return i;
32                }
33           
34        }
35
36        return -1;
37        
38    }
39};