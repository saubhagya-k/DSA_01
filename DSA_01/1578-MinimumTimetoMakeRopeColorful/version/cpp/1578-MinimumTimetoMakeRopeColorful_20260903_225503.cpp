// Last updated: 03/09/2026, 22:55:03
1class Solution {
2public:
3    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
4
5        int n = plantTime.size();
6
7        vector<pair<int,int>> vec(n); //{plantTime,growTime}
8
9        for(int i=0;i<n;i++){
10            vec[i] = {plantTime[i],growTime[i]};
11        }
12
13        auto Lamda = [](pair<int,int>&P1,pair<int,int>&P2){
14            return P1.second > P2.second;
15        };
16
17        sort(vec.begin(),vec.end(),Lamda);
18
19
20        int maxBloomDays = 0;
21
22        int prevplantDays = 0;
23
24        for(int i=0;i<n;i++){
25            int currPlantTime = vec[i].first;
26            int currGrowTime = vec[i].second;
27
28            prevplantDays += currPlantTime;
29
30            int bloomingTime = prevplantDays+currGrowTime;
31
32            maxBloomDays = max(maxBloomDays,bloomingTime);
33        }
34
35
36        return maxBloomDays;
37        
38    }
39};