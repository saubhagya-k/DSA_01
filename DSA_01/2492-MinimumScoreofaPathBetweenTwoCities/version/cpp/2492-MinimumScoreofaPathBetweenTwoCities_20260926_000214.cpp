// Last updated: 26/09/2026, 00:02:14
1class Solution {
2public:
3
4void dfs(int u,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&visited,int &result){
5
6    visited[u] =  true;
7
8    for(auto &ok : adj[u]){
9
10        int v = ok.first;
11        int d = ok.second;
12
13        result = min(result,d);
14
15        if(!visited[v]){
16            dfs(v,adj,visited,result);
17        }
18
19    }
20
21}
22    int minScore(int n, vector<vector<int>>& roads) {
23
24        unordered_map<int,vector<pair<int,int>>>adj;
25
26        for(auto &vec : roads){
27            int u = vec[0];
28            int v = vec[1];
29            int dist = vec[2];
30
31            adj[u].push_back({v,dist});
32            adj[v].push_back({u,dist});
33        }
34
35        vector<bool>visited(n,false);
36
37        int result = INT_MAX;
38
39        dfs(1,adj,visited,result);
40
41         return result;
42
43       
44
45
46        
47    }
48    
49};