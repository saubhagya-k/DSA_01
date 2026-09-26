// Last updated: 26/09/2026, 13:46:57
1class Solution {
2public:
3    long long countPairs(int n, vector<vector<int>>& edges) {
4        // Step 1: Build the graph (Adjacency List)
5        vector<vector<int>> adj(n);
6        for (auto& edge : edges) {
7            adj[edge[0]].push_back(edge[1]);
8            adj[edge[1]].push_back(edge[0]);
9        }
10        
11        vector<bool> visited(n, false);
12        long long total_pairs = 0;
13        long long remaining_nodes = n;
14        
15        // Step 2: Loop through every node to find all different graphs (components)
16        for (int i = 0; i < n; i++) {
17            if (!visited[i]) {
18                long long component_size = 0;
19                queue<int> q;
20                
21                // Start BFS from the unvisited node
22                q.push(i);
23                visited[i] = true;
24                
25                while (!q.empty()) {
26                    int curr = q.front();
27                    q.pop();
28                    component_size++; // Count this node
29                    
30                    // Explore neighbors
31                    for (int neighbor : adj[curr]) {
32                        if (!visited[neighbor]) {
33                            visited[neighbor] = true;
34                            q.push(neighbor);
35                        }
36                    }
37                }
38                
39                // Step 3: Run your multiplication logic
40                remaining_nodes -= component_size;
41                total_pairs += component_size * remaining_nodes;
42            }
43        }
44        
45        return total_pairs;
46    }
47};
48