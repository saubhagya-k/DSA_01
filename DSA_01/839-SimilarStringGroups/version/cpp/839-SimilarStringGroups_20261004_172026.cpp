// Last updated: 04/10/2026, 17:20:26
1class Solution {
2public:
3
4void BFS(int i,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
5
6    queue<int>q;
7    q.push(i);
8
9    visited[i] = true;
10
11    while(!q.empty()){
12        int u = q.front();
13        q.pop();
14
15        for(int &v:adj[u]){
16            if(!visited[v]){
17                q.push(v);
18
19                visited[v] = true;
20            }
21
22
23        }
24    }
25
26
27}
28
29bool isSimillar(string &s1,string &s2){
30
31    int n = s1.length();
32    int diff = 0;
33
34    for(int i=0;i<n;i++){
35
36        if(s1[i]!=s2[i]){
37            diff++;
38        }
39
40    }
41
42    return diff==2 || diff==0;
43    
44}
45    int numSimilarGroups(vector<string>& strs) {
46
47        int n = strs.size();
48
49        unordered_map<int,vector<int>>adj;
50
51
52        for(int i=0;i<n;i++){
53            for(int j=0;j<n;j++){
54                if(isSimillar(strs[i],strs[j])){
55                    adj[i].push_back(j);
56                    adj[j].push_back(i);
57                }
58            }
59        }
60
61        vector<bool>visited(n,false);
62
63        int count = 0;
64
65        for(int i=0;i<n;i++){
66
67            if(!visited[i]){
68            BFS(i,adj,visited);
69            count++;
70
71            }
72        }
73
74        return count;
75        
76    }
77};