// Last updated: 06/08/2026, 18:55:51
1class Solution {
2public:
3void dfs(vector<vector<int>>& stones,int index, vector<int>&visited){
4    visited[index] = 1;
5
6    for(int i=0;i<stones.size();i++){
7
8        if(visited[i] == 0 && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])){
9            dfs(stones,i,visited);
10        }
11
12    }
13}
14    int removeStones(vector<vector<int>>& stones) {
15
16        int n = stones.size();
17        int group = 0;
18
19        vector<int>visited(n,0);
20
21        for(int i=0;i<n;i++){
22
23            if(visited[i] == 1){
24                continue;
25            }
26            dfs(stones,i,visited);
27            group++;
28        }
29
30        return (n-group);
31        
32    }
33};