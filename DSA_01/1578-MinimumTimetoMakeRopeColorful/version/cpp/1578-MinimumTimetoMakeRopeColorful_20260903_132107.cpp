// Last updated: 03/09/2026, 13:21:07
1class Solution {
2public:
3    int minCost(string colors, vector<int>& neededTime) {
4
5        int n = colors.size();
6
7        int time = 0;
8        int preMax = 0;
9
10        for(int i=0;i<n;i++){
11
12            if(i>0 && colors[i]!= colors[i-1]){
13                preMax = 0;
14            }
15
16            int curr = neededTime[i];
17
18            time += min(preMax,curr);
19
20            preMax = max(preMax,curr);
21
22        }
23
24        return time;
25        
26    }
27};