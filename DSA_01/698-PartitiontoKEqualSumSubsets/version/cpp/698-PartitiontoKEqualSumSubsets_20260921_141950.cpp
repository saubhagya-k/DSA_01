// Last updated: 21/09/2026, 14:19:50
1class Solution {
2public:
3    vector<int> distributeCandies(int candies, int num_people) {
4
5        int gave = 1;
6
7        vector<int>final(num_people,0);
8
9
10        while(candies>0){
11
12
13            for(int i=0;i<num_people;i++){
14
15            if(candies<=0){
16                break;
17            }
18
19            final[i]+= min(gave,candies);
20
21            candies-=gave;
22
23            gave++;
24
25
26            }
27
28
29
30
31        }
32
33        return final;
34        
35    }
36};