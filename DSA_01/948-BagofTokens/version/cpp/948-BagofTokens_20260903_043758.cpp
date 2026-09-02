// Last updated: 03/09/2026, 04:37:58
1class Solution {
2public:
3    int numRescueBoats(vector<int>& people, int limit) {
4
5        sort(people.begin(),people.end());
6
7        int n = people.size();
8
9        int i = 0;
10        int j = n-1;
11
12      int   boatCount = 0;
13     
14
15        while(i<=j){
16
17            if(people[i]+people[j]<=limit){
18                boatCount++;
19                i++;
20                j--;
21
22               
23
24            }
25            else if(people[j]<=limit){
26                boatCount++;
27                j--;
28            }
29
30
31        }
32
33        return boatCount;
34        
35    }
36};