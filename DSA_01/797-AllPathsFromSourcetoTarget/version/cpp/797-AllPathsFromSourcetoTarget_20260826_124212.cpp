// Last updated: 26/08/2026, 12:42:12
1class Solution {
2public:
3
4int DFS(unordered_map<int,vector<int>>&adj,int current,int parent,vector<bool>& hasApple){
5
6    int time = 0;
7
8    for(int& child:adj[current]){
9        if(child == parent){
10            continue;
11        }
12        int time_require = DFS(adj,child,current,hasApple);
13
14        if(time_require>0 || hasApple[child]){
15            time += time_require+2;
16        }
17    }
18
19    return time;
20
21}
22    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
23
24        unordered_map<int,vector<int>>adj;
25
26        for(auto& vec:edges){
27
28            int u = vec[0];
29            int v = vec[1];
30
31            adj[u].push_back(v);
32            adj[v].push_back(u);
33
34        }
35
36        return DFS(adj,0,-1,hasApple);
37        
38    }
39};