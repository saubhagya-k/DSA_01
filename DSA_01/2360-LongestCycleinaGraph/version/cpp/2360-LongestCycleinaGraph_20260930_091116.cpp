// Last updated: 30/09/2026, 09:11:16
1class Solution {
2public:
3
4int result;
5
6void dfs(int u,vector<int>& edges,vector<int>&count,vector<bool>&visited,vector<bool>&inRecursion){
7
8    if(u!=-1){
9        visited[u] = true;
10        inRecursion[u] = true;
11
12        int v = edges[u];
13
14        if(v!=-1 && !visited[v]){
15             count[v] = count[u]+1;
16
17             dfs(v,edges,count,visited,inRecursion);
18        }
19        else if(v!=-1 && inRecursion[v] == true){
20
21            result = max(result,count[u]-count[v]+1);
22
23        }
24
25        inRecursion[u] = false;
26    }
27
28}
29    int longestCycle(vector<int>& edges) {
30
31        int n = edges.size();
32
33        vector<bool>visited(n,false);
34
35        vector<bool>inRecursion(n,false);
36
37        vector<int>count(n,1);
38
39        result = -1; 
40
41
42
43        for(int i=0;i<n;i++){
44            if(!visited[i]){
45
46                dfs(i,edges,count,visited,inRecursion);
47
48            }
49        }
50
51        return result;
52        
53    }
54};