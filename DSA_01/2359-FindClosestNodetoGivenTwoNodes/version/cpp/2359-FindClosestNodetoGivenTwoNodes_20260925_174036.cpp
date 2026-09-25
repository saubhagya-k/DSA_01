// Last updated: 25/09/2026, 17:40:36
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        // 1. Build Adjacency List
5        vector<vector<pair<int, int>>> adj(n);
6        for (auto& flight : flights) {
7            adj[flight[0]].push_back({flight[1], flight[2]});
8        }
9
10        // 2. Track the minimum cost to reach each node
11        vector<int> minCost(n, INT_MAX);
12        minCost[src] = 0;
13
14        // 3. Queue stores: {currentNode, currentCost}
15        queue<pair<int, int>> q;
16        q.push({src, 0});
17
18        int stops = 0;
19
20        // Loop level by level up to k stops
21        while (!q.empty() && stops <= k) {
22            int size = q.size();
23            
24            while (size--) {
25                auto [node, cost] = q.front();
26                q.pop();
27
28                for (auto& neighbor : adj[node]) {
29                    int nextNode = neighbor.first;
30                    int price = neighbor.second;
31
32                    // If we find a cheaper way to reach nextNode, update and push to queue
33                    if (cost + price < minCost[nextNode]) {
34                        minCost[nextNode] = cost + price;
35                        q.push({nextNode, minCost[nextNode]});
36                    }
37                }
38            }
39            stops++; // Move to the next stop level
40        }
41
42        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
43    }
44};
45