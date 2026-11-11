// Last updated: 11/11/2026, 23:06:59
1class Solution {
2public:
3    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
4
5        long long option1 = (1LL * need1 * cost1) + (1LL * need2 * cost2);
6
7        long long maxOne = max(need1,need2);
8
9        long long option2 = (1LL * maxOne * costBoth);
10
11        long long overlap = min(need1,need2);
12
13        long long option3 = (1LL * overlap * costBoth);
14
15
16        if(need1>need2){
17            option3+= 1LL * (need1-need2) * cost1;
18        }
19        else{
20            option3+= 1LL * (need2-need1) * cost2;
21        }
22
23        return min({option1,option2,option3});
24        
25    }
26};