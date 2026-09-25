// Last updated: 25/09/2026, 16:02:01
1class Solution {
2public:
3
4int n;
5
6void dfs(vector<int>& edges,int node,vector<int>& dist,vector<int>&visited){
7
8    visited[node] = true;
9
10    int v = edges[node];
11
12    if(v!=-1 && !visited[v]){
13        visited[v] = true;
14
15        dist[v] = 1+dist[node];
16
17        dfs(edges,v,dist,visited);
18
19    }
20
21}
22    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
23
24        n = edges.size();
25
26        vector<int> dist1(n,INT_MAX);
27        vector<int> dist2(n,INT_MAX);
28
29        vector<int>visited1(n,false);
30        vector<int>visited2(n,false);
31
32        dist1[node1] = 0;
33        dist2[node2] = 0;
34
35        dfs(edges,node1,dist1,visited1);
36        dfs(edges,node2,dist2,visited2);
37
38        int minDistance = -1;
39        int minDistancetillNode = INT_MAX;
40
41        for(int i=0;i< n;i++){
42            int maxD = max(dist1[i],dist2[i]);
43
44            if(minDistancetillNode>maxD){
45                minDistancetillNode = maxD;
46                minDistance = i;
47            }
48        }
49
50
51        return minDistance;
52
53
54
55
56
57
58
59
60
61        
62    }
63};