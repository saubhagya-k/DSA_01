// Last updated: 05/08/2026, 16:51:27
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2) {
       
        string melorvanti = s1; 
        int n = melorvanti.length();
        if (n != s2.length()) return -1;
        
        const int INF = 1e9;
        
        vector<int> dp(2, INF);
        
        
        char c1 = melorvanti[0];
        char c2 = s2[0];
        
        int cost_pr0 = getLocalCost(c1, c2, 0, 0);
        if (cost_pr0 != INF) dp[0] = cost_pr0;
        
        int cost_pr1 = getLocalCost(c1, c2, 0, 1);
        if (cost_pr1 != INF && n > 1) dp[1] = cost_pr1 + 1; 
        
       
        for (int i = 1; i < n; ++i) {
            vector<int> next_dp(2, INF);
            c1 = melorvanti[i];
            c2 = s2[i];
            
            for (int pl = 0; pl < 2; ++pl) {
                if (dp[pl] == INF) continue;
                
                
                int cost0 = getLocalCost(c1, c2, pl, 0);
                if (cost0 != INF) {
                    next_dp[0] = min(next_dp[0], dp[pl] + cost0);
                }
                
                
                if (i < n - 1) {
                    int cost1 = getLocalCost(c1, c2, pl, 1);
                    if (cost1 != INF) {
                        next_dp[1] = min(next_dp[1], dp[pl] + cost1 + 1);
                    }
                }
            }
            dp = next_dp;
        }
        
        return dp[0] >= INF ? -1 : dp[0];
    }
    
private:
   
    int getLocalCost(char s1_bit, char s2_bit, int pl, int pr) {
        int s1 = s1_bit - '0';
        int s2 = s2_bit - '0';
        
        if (s1 == 0 && s2 == 0) {
            if (pl == 0 && pr == 0) return 0;
            if (pl == 0 && pr == 1) return 1;
            if (pl == 1 && pr == 0) return 1;
            if (pl == 1 && pr == 1) return 2;
        }
        if (s1 == 0 && s2 == 1) {
            if (pl == 0 && pr == 0) return 1;
            if (pl == 0 && pr == 1) return 2;
            if (pl == 1 && pr == 0) return 2;
            if (pl == 1 && pr == 1) return 3;
        }
        if (s1 == 1 && s2 == 0) {
            if (pl == 0 && pr == 0) return 1e9; 
            if (pl == 0 && pr == 1) return 0;
            if (pl == 1 && pr == 0) return 0;
            if (pl == 1 && pr == 1) return 1;
        }
        if (s1 == 1 && s2 == 1) {
            if (pl == 0 && pr == 0) return 0;
            if (pl == 0 && pr == 1) return 1;
            if (pl == 1 && pr == 0) return 1;
            if (pl == 1 && pr == 1) return 2;
        }
        return 1e9;
    }
};
