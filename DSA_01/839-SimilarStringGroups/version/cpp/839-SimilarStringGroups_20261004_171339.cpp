// Last updated: 04/10/2026, 17:13:39
1class Solution {
2public:
3
4void DFS(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
5
6    visited[u] = true;
7
8    for(auto &v : adj[u]){
9
10        if(!visited[v]){
11        DFS(v,adj,visited);
12        }
13    }
14}
15
16bool isSimillar(string &s1,string &s2){
17
18    int n = s1.length();
19    int diff = 0;
20
21    for(int i=0;i<n;i++){
22
23        if(s1[i]!=s2[i]){
24            diff++;
25        }
26
27    }
28
29    return diff==2 || diff==0;
30    
31}
32    int numSimilarGroups(vector<string>& strs) {
33
34        int n = strs.size();
35
36        unordered_map<int,vector<int>>adj;
37
38
39        for(int i=0;i<n;i++){
40            for(int j=0;j<n;j++){
41                if(isSimillar(strs[i],strs[j])){
42                    adj[i].push_back(j);
43                    adj[j].push_back(i);
44                }
45            }
46        }
47
48        vector<bool>visited(n,false);
49
50        int count = 0;
51
52        for(int i=0;i<n;i++){
53
54            if(!visited[i]){
55            DFS(i,adj,visited);
56            count++;
57
58            }
59        }
60
61        return count;
62        
63    }
64};