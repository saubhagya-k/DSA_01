// Last updated: 26/08/2026, 00:51:06
1class Solution {
2public:
3
4void dfs(vector<vector<int>>& graph, vector<vector<int>>& result,vector<int>& temp,int u,int target){
5
6    temp.push_back(u);
7
8    if(u == target){
9        result.push_back(temp);
10    }
11
12   else{
13    for(int &v:graph[u]){
14        dfs(graph,result,temp,v,target);
15    }
16   }
17   temp.pop_back();
18}
19
20
21    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
22
23        int n = graph.size();
24
25        int source = 0;
26        int target = n-1;
27
28        vector<vector<int>>result;
29        vector<int>temp;
30
31        dfs(graph,result,temp,source,target);
32
33        return result;
34        
35    }
36};