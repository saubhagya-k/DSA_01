// Last updated: 18/11/2026, 14:01:58
// very tricky question
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4
5        int left = 1;
6
7        int right = *max_element(piles.begin(),piles.end());
8
9
10        while(left<right){
11
12           int mid = left+(right-left)/2;
13           long long hours_spent = 0;
14
15           for(int pile:piles){
16            hours_spent+=(static_cast<long long >(pile)+mid-1)/ mid;
17
18
19           }
20
21           if(hours_spent<=h){
22            right = mid;
23           }
24           else{
25            left = mid+1;
26           }
27        }
28
29
30        return left;
31
32
33
34
35
36        
37    }
38};