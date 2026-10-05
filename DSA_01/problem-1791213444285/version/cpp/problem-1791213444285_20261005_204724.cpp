// Last updated: 05/10/2026, 20:47:24
1class Solution {
2public:
3int n = 0;
4bool helper(int i,vector<int>& candies,int extraCandies){
5
6    for(int j=0;j<n;j++){
7
8        if(candies[i]+extraCandies<candies[j]){
9
10           return false;
11
12        }
13        
14
15    }
16
17   return true;
18
19
20}
21    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
22
23        n = candies.size();
24
25        vector<bool>final;
26
27        for(int i=0;i<n;i++){
28            final.push_back(helper(i,candies,extraCandies));
29
30            
31        }
32
33        return final;
34        
35    }
36};