// Last updated: 05/08/2026, 16:55:25
class Solution {
public:
    vector<int> state; 
    // 0 = unvisited
    // 1 = visiting (in DFS stack)
    // 2 = safe

    bool dfs(int node, vector<vector<int>>& graph) {

        // if already visited, return whether it's safe
        if(state[node] != 0)
            return state[node] == 2;

        state[node] = 1; // mark as visiting

        for(int next : graph[node]) {
            // if cycle found or neighbor is unsafe
            if(state[next] == 1 || !dfs(next, graph))
                return false;
        }

        state[node] = 2; // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        state.assign(n, 0);

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(dfs(i, graph))
                ans.push_back(i);
        }
        return ans;
    }
};
