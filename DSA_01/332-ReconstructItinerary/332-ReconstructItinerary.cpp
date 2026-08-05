// Last updated: 05/08/2026, 16:58:01

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string airport) {
        auto &pq = adj[airport];
        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next);
        }
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &t : tickets) {
            adj[t[0]].push(t[1]);
        }

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
