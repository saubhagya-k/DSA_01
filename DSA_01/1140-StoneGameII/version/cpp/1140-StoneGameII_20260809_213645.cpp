// Last updated: 09/08/2026, 21:36:45
1class Solution {
2public:
3    int stoneGameII(vector<int>& piles) {
4        vector<vector<int>> memo(piles.size(), vector<int>(piles.size()));
5        vector<int> suffixSum = piles;
6        for (int i = suffixSum.size() - 2; i >= 0; --i)
7            suffixSum[i] += suffixSum[i + 1];
8        return maxStones(suffixSum, 1, 0, memo);
9    }
10
11    int maxStones(vector<int>& suffixSum, int maxTillNow, int currIndex,
12                  vector<vector<int>>& memo) {
13        if (currIndex + 2 * maxTillNow >= suffixSum.size())
14            return suffixSum[currIndex];
15        if (memo[currIndex][maxTillNow] > 0) return memo[currIndex][maxTillNow];
16        int res = INT_MAX;
17
18        for (int i = 1; i <= 2 * maxTillNow; ++i) {
19            res = min(res, maxStones(suffixSum, max(i, maxTillNow),
20                                     currIndex + i, memo));
21        }
22        memo[currIndex][maxTillNow] = suffixSum[currIndex] - res;
23        return memo[currIndex][maxTillNow];
24    }
25};