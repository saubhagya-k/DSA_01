// Last updated: 12/09/2026, 23:49:07
1class Solution {
2public:
3    vector<int> maximumWeight(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        vector<tuple<int, int, int, int>> arr;
6        for (int i = 0; i < n; i++) {
7            int l = intervals[i][0], r = intervals[i][1],
8                weight = intervals[i][2];
9            arr.emplace_back(l, r, weight, i);
10        }
11        // Sort by right endpoint.
12        sort(arr.begin(), arr.end(),
13             [](auto&& a, auto&& b) { return get<1>(a) < get<1>(b); });
14
15        vector<vector<long long>> dp(n + 1, vector<long long>(5));
16        vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));
17        for (int i = 0; i < n; i++) {
18            auto [l, r, weight, idx] = arr[i];
19            // Use binary search to find intervals whose right endpoints are
20            // smaller than l.
21            int k = lower_bound(arr.begin(), arr.begin() + i, l,
22                                [](const tuple<int, int, int, int>& t,
23                                   int val) { return get<1>(t) < val; }) -
24                    arr.begin();
25
26            for (int j = 1; j < 5; j++) {
27                long long s1 = dp[i][j];
28                long long s2 = dp[k][j - 1] + weight;
29                if (s1 > s2) {
30                    dp[i + 1][j] = dp[i][j];
31                    indices[i + 1][j] = indices[i][j];
32                    continue;
33                }
34
35                vector<int> newIndex = indices[k][j - 1];
36                newIndex.push_back(idx);
37                sort(newIndex.begin(), newIndex.end());
38                if (s1 == s2 && indices[i][j] < newIndex) {
39                    newIndex = indices[i][j];
40                }
41                dp[i + 1][j] = s2;
42                indices[i + 1][j] = newIndex;
43            }
44        }
45
46        return indices[n][4];
47    }
48};