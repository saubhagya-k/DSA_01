// Last updated: 05/08/2026, 16:51:52
#include <vector>
#include <queue>
#include <unordered_set>
#include <numeric>

class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
       
        std::vector<std::vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        
        std::vector<bool> isSuspicious(n, false);
        std::queue<int> q;
        
        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!isSuspicious[neighbor]) {
                    isSuspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

      
        bool canRemove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
           
            if (!isSuspicious[u] && isSuspicious[v]) {
                canRemove = false;
                break;
            }
        }

      
        std::vector<int> result;
        if (!canRemove) {
           
            result.resize(n);
            std::iota(result.begin(), result.end(), 0);
        } else {
           
            for (int i = 0; i < n; ++i) {
                if (!isSuspicious[i]) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};
