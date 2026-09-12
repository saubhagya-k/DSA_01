// Last updated: 12/09/2026, 15:13:44
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4
5        sort(costs.begin(),costs.end());
6
7        int count = 0;
8
9
10        int n = costs.size();
11
12        for(int i=0;i<n;i++){
13
14            if(costs[i]<=coins){
15
16            coins-=costs[i];
17
18            count++;
19
20            }
21
22            else{
23                break;
24            }
25
26        }
27        
28        return count;
29    }
30};