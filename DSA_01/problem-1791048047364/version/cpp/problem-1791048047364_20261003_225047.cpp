// Last updated: 03/10/2026, 22:50:47
1class Solution {
2public:
3    // 1. FIXED: Removed 'int count = 0;' here because it conflicts with the 'count' parameter below.
4
5    bool DFS(int u, string &colors, unordered_map<int, vector<int>>& graph, 
6             vector<vector<int>>& count, vector<bool>& visited, vector<bool>& inRecursion) {
7
8       visited[u] = true;
9       inRecursion[u] = true;
10
11       // Open the loop
12       for(auto v : graph[u]) {
13            if(inRecursion[v]) return true;
14
15            if (!visited[v]) {
16                if (DFS(v, colors, graph, count, visited, inRecursion)) { // 2. FIXED: Swapped parameter order to match function signature
17                    return true; 
18                }
19            }
20
21            for (int c = 0; c < 26; c++) {
22                count[u][c] = max(count[u][c], count[v][c]);
23            }
24       } // 3. FIXED: The loop now closes HERE, keeping 'v' valid for all lines above!
25
26       // 4. FIXED: Added logic to include the current node's own color into its path tracker
27       int colorIdx = colors[u] - 'a';
28       count[u][colorIdx]++;
29
30       // 5. FIXED: Added backtracking step and missing return statement
31       inRecursion[u] = false; 
32       return false;
33    }
34
35    int largestPathValue(string colors, vector<vector<int>>& edges) {
36        unordered_map<int, vector<int>> graph;
37        
38        // 6. FIXED: Changed edges.size() to colors.size() so the tracking vectors match the number of nodes
39        int n = colors.size(); 
40
41        for(auto edge : edges) {
42            int u = edge[0];
43            int v = edge[1];
44            graph[u].push_back(v);
45        }
46
47        vector<bool> visited(n, false);
48        vector<bool> inRecursion(n, false);
49        vector<vector<int>> count(n, vector<int>(26, 0));
50
51        // 7. FIXED: Changed variable name to maxColorValue to match the variable used at the bottom
52        int maxColorValue = 0; 
53
54        for(int i = 0; i < n; i++) {
55            if(!visited[i]) {
56                if(DFS(i, colors, graph, count, visited, inRecursion)) {
57                    return -1;
58                }
59            }
60        }
61
62        for (int i = 0; i < n; i++) {
63            for (int c = 0; c < 26; c++) {
64                maxColorValue = max(maxColorValue, count[i][c]);
65            }
66        }
67
68        return maxColorValue;
69    }
70};
71