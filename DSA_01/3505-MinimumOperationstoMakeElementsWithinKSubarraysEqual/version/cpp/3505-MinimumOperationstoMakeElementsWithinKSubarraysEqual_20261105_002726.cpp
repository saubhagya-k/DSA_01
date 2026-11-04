// Last updated: 05/11/2026, 00:27:26
1class Solution {
2public:
3    long long minOperations(vector<int>& nums, int x, int k) {
4        int n = nums.size();
5        priority_queue<int> left;
6        priority_queue<int, vector<int>, greater<int>> right;
7        unordered_map<int, int> delayed;
8        int leftSize = 0, rightSize = 0;
9        vector<long long> ops(n);
10        long long sumL = 0, sumR = 0;
11
12        auto prune = [&](auto& heap) {
13            while (!heap.empty()) {
14                if (delayed[heap.top()]) {
15                    --delayed[heap.top()];
16                    heap.pop();
17                } else {
18                    break;
19                }
20            }
21        };
22
23        auto balance = [&]() {
24            if (leftSize > rightSize + 1) {
25                int num = left.top();
26                right.push(num);
27                sumR += num;
28                sumL -= num;
29                left.pop();
30                ++rightSize;
31                --leftSize;
32                prune(left);
33            } else if (rightSize > leftSize) {
34                int num = right.top();
35                left.push(num);
36                sumL += num;
37                sumR -= num;
38                right.pop();
39                ++leftSize;
40                --rightSize;
41                prune(right);
42            }
43        };
44
45        for (int i = 0; i < n; i++) {
46            if (left.empty() || nums[i] <= left.top()) {
47                left.push(nums[i]);
48                ++leftSize;
49                sumL += nums[i];
50            } else {
51                right.push(nums[i]);
52                ++rightSize;
53                sumR += nums[i];
54            }
55            balance();
56            if (i >= x) {
57                int num = nums[i - x];
58                if (num <= left.top()) {
59                    --leftSize;
60                    ++delayed[num];
61                    sumL -= num;
62                    if (num == left.top()) {
63                        prune(left);
64                    }
65                } else {
66                    --rightSize;
67                    ++delayed[num];
68                    sumR -= num;
69                    if (num == right.top()) {
70                        prune(right);
71                    }
72                }
73                balance();
74            }
75
76            if (i >= x - 1) {
77                long long mid = left.top();
78                ops[i] = sumR - sumL + mid * (leftSize - rightSize);
79            }
80        }
81
82        vector<vector<long long>> dp(n, vector<long long>(k + 1, LLONG_MAX));
83
84        for (int i = 0; i < n; i++) {
85            dp[i][0] = 0;
86        }
87        for (int j = 1; j <= k; j++) {
88            if (j == 1) {
89                dp[x - 1][j] = ops[x - 1];
90            } else {
91                dp[j * x - 1][j] = dp[(j - 1) * x - 1][j - 1] + ops[j * x - 1];
92            }
93        }
94        for (int j = 1; j <= k; j++) {
95            for (int i = j * x; i < n; i++) {
96                dp[i][j] = min(dp[i - x][j - 1] + ops[i], dp[i - 1][j]);
97            }
98        }
99
100        return dp[n - 1][k];
101    }
102};