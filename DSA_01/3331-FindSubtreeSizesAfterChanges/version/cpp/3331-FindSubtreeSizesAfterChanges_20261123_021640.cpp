// Last updated: 23/11/2026, 02:16:40
1class Solution {
2public:
3
4unordered_map<int,vector<int>>adj;
5
6vector<int>resultSize;
7vector<int>last;
8
9void dfs(int currentNode,vector<int>& parent,string& s){
10
11    int c = s[currentNode]-'a';
12
13   int nearestA = last[c];
14
15   last[c] = currentNode;
16
17   for(int child : adj[currentNode]){
18    dfs(child,parent,s);
19   } 
20
21   last[c] = nearestA;
22
23   if (currentNode != 0) {
24            int newParent = parent[currentNode];
25            if (nearestA != -1) {
26                newParent = nearestA;
27            }
28            parent[currentNode] = newParent;
29            resultSize[newParent] += resultSize[currentNode];
30
31   }
32
33
34
35}
36    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
37
38        int n  = parent.size();
39
40
41        for(int i = 1;i<n;i++){
42            int u = parent[i];
43            int v = i;
44
45            adj[u].push_back(v);
46        }
47
48        resultSize.assign(n,1);
49        last.assign(26,-1);
50
51        dfs(0,parent,s);
52
53
54        return resultSize;
55        
56    }
57};