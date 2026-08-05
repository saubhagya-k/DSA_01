// Last updated: 05/08/2026, 16:53:07
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // visited[i] = whether point i is already in MST
        vector<bool> visited(n, false);

        // minDist[i] = minimum cost to connect point i to MST
        vector<int> minDist(n, INT_MAX);

        // start from point 0
        minDist[0] = 0;

        int totalCost = 0;

        // MST will include all n points
        for (int i = 0; i < n; i++) {
            int u = -1;

            // pick unvisited point with minimum connection cost
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            // include point u in MST
            visited[u] = true;
            totalCost += minDist[u];

            // update distances for remaining points
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return totalCost;
    }
};
