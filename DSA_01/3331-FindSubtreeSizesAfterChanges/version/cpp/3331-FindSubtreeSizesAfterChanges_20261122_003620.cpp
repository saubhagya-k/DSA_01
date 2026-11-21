// Last updated: 22/11/2026, 00:36:20
1#include <iostream>
2#include <vector>
3#include <string>
4
5using namespace std;
6
7class Solution {
8public:
9    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
10        int n = parent.size();
11        vector<vector<int>> adj(n);
12        
13        // Build the initial tree
14        for (int i = 1; i < n; ++i) {
15            adj[parent[i]].push_back(i);
16        }
17
18        vector<int> newParent = parent;
19        vector<int> lastSeen(26, -1);
20
21        // First DFS: Find the closest ancestor with the same character
22        auto findNewParents = [&](auto& self, int u) -> void {
23            int charIdx = s[u] - 'a';
24            int prevAncestor = lastSeen[charIdx];
25            
26            if (prevAncestor != -1) {
27                newParent[u] = prevAncestor;
28            }
29            
30            lastSeen[charIdx] = u;
31            
32            for (int v : adj[u]) {
33                self(self, v);
34            }
35            
36            // Backtrack
37            lastSeen[charIdx] = prevAncestor;
38        };
39
40        findNewParents(findNewParents, 0);
41
42        // Build the updated tree using newParent
43        vector<vector<int>> newAdj(n);
44        for (int i = 1; i < n; ++i) {
45            newAdj[newParent[i]].push_back(i);
46        }
47
48        vector<int> answer(n, 0);
49
50        // Second DFS: Calculate subtree sizes in the final tree
51        auto calcSizes = [&](auto& self, int u) -> int {
52            int totalSize = 1;
53            for (int v : newAdj[u]) {
54                totalSize += self(self, v);
55            }
56            return answer[u] = totalSize;
57        };
58
59        calcSizes(calcSizes, 0);
60        return answer;
61    }
62};
63