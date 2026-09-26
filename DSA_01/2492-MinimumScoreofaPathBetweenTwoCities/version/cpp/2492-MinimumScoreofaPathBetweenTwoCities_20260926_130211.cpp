// Last updated: 26/09/2026, 13:02:11
1class Solution {
2public:
3int count = 0;
4
5void dfs(int u,int parent,unordered_map<int,vector<pair<int,int>>>&adj){
6
7    for(auto &si: adj[u]){
8        int v = si.first;
9        int check = si.second;
10
11        if(v!=parent){
12            if(check==0){
13                count++;
14            }
15
16            dfs(v,u,adj);
17        }
18    }
19}
20    int minReorder(int n, vector<vector<int>>& connections) {
21
22        unordered_map<int,vector<pair<int,int>>>adj;
23
24        for(auto &s :connections){
25            int u = s[0];
26            int v = s[1];
27
28            adj[u].push_back({v,0}); // asli;
29            adj[v].push_back({u,1}); // nakli 
30        }
31
32        dfs(0,-1,adj);
33
34        return count;
35
36
37        
38        
39    }
40};