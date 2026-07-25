class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e15; 

        // 1. FIXED: Changed 'vector<long>' to 'vector<long long>'
        vector<vector<long long>> flw(26, vector<long long>(26, INF));

        // 2. FIXED: Added initialization for the diagonal elements
        for (int i = 0; i < 26; i++) {
            flw[i][i] = 0;
        }

        for (size_t i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            flw[u][v] = min(flw[u][v], (long long)cost[i]);
        }

        for(int via = 0; via < 26; via++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    flw[i][j] = min(flw[i][j], flw[i][via] + flw[via][j]);
                }
            }
        }

        long long total_cost = 0;
        for (size_t i = 0; i < source.length(); ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            
            if (flw[u][v] == INF) {
                return -1;
            }
            total_cost += flw[u][v];
        }

        return total_cost;
    } 
};
