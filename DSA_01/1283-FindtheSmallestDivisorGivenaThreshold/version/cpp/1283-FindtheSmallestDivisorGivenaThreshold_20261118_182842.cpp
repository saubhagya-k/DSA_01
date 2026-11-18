// Last updated: 18/11/2026, 18:28:42
1class Solution {
2public:
3    int smallestDivisor(vector<int>& nums, int threshold) {
4
5        int left = 1;
6        int right = *max_element(nums.begin(),nums.end());
7
8        
9
10        while(left<right){
11            int mid = left+(right-left)/2;
12            long long  bigyohada = 0;
13
14            for(int num:nums){
15
16
17                int temp = num/mid;
18
19                if(num%mid!=0){
20                    temp++;
21                }
22
23                bigyohada += temp;
24
25                
26
27            }
28
29            if(bigyohada>threshold){
30                left = mid+1;
31            }
32
33            else{
34                right = mid;
35            }
36        }
37
38        return left;
39
40
41        
42    }
43};