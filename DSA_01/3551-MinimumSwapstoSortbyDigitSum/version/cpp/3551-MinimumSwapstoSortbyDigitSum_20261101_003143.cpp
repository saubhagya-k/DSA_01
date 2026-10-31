// Last updated: 01/11/2026, 00:31:43
1class Solution {
2public:
3    int minSwaps(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> digitSum(n);
6        for (int i = 0; i < n; i++) {
7            int x = nums[i], sum = 0;
8            while (x > 0) {
9                sum += x % 10;
10                x /= 10;
11            }
12            digitSum[i] = sum;
13        }
14
15        vector<int> indices(n);
16        iota(indices.begin(), indices.end(), 0);
17        sort(indices.begin(), indices.end(), [&](int a, int b) {
18            if (digitSum[a] != digitSum[b]) {
19                return digitSum[a] < digitSum[b];
20            }
21            return nums[a] < nums[b];
22        });
23
24        vector<int> targetPos(n);
25        for (int pos = 0; pos < n; pos++) {
26            targetPos[indices[pos]] = pos;
27        }
28
29        vector<int> parent(n);
30        iota(parent.begin(), parent.end(), 0);
31        int components = n;
32
33        function<int(int)> find = [&](int x) -> int {
34            if (parent[x] != x) {
35                parent[x] = find(parent[x]);
36            }
37            return parent[x];
38        };
39
40        for (int i = 0; i < n; i++) {
41            int ri = find(i);
42            int rj = find(targetPos[i]);
43            if (ri != rj) {
44                parent[ri] = rj;
45                components--;
46            }
47        }
48
49        return n - components;
50    }
51};