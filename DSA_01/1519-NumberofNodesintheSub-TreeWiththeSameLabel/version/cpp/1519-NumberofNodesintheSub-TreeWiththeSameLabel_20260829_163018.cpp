// Last updated: 29/08/2026, 16:30:18
1class Solution {
2public:
3
4vector<int>dfs(unordered_map<int,vector<int>>&adj, int curr,int parent,vector<int>&result,string&labels){
5
6    vector<int>myCount(26,0);
7
8    char mylabel = labels[curr];
9    myCount[mylabel-'a'] = 1;
10
11    for(int &v : adj[curr]){
12        if(v==parent) continue;
13
14
15        vector<int>child_count(26,0);
16
17        child_count = dfs(adj,v,curr,result,labels);
18
19        for(int i=0;i<26;i++){
20            myCount[i] += child_count[i];
21        }
22
23        
24    }
25    result[curr] = myCount[mylabel-'a'];
26
27        return myCount;
28
29
30
31}
32    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
33
34        unordered_map<int,vector<int>>adj;
35
36        for(auto &vec :edges){
37            int u = vec[0];
38            int v = vec[1];
39
40            adj[u].push_back(v);
41            adj[v].push_back(u);
42        }
43
44        vector<int>result(n,0);
45
46        dfs(adj,0,-1,result,labels);
47
48        return result;
49
50
51        
52        
53    }
54};