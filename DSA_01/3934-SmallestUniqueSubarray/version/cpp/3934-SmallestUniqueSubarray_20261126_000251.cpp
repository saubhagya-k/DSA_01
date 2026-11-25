// Last updated: 26/11/2026, 00:02:51
1using ll = long long;
2
3class Solution {
4public:
5    int smallestUniqueSubarray(vector<int>& nums) {
6        constexpr ll MOD = 1000000007LL;
7        constexpr ll BASE = 911382323LL;
8
9        int n = (int)nums.size();
10        vector<ll> h(n + 1);
11        vector<ll> p(n + 1);
12        p[0] = 1;
13
14        // Compute prefix hashes and powers of BASE
15        for (int i = 0; i < n; ++i) {
16            h[i + 1] = (h[i] * BASE + nums[i]) % MOD;
17            p[i + 1] = p[i] * BASE % MOD;
18        }
19
20        auto check = [&](int len) {
21            unordered_map<ll, int> cnt;
22
23            for (int l = 0; l + len <= n; ++l) {
24                int r = l + len;
25
26                ll key = (h[r] - h[l] * p[len] % MOD + MOD) % MOD;
27                ++cnt[key];
28            }
29
30            for (auto& [key, times] : cnt) {
31                if (times == 1) {
32                    return true;
33                }
34            }
35            return false;
36        };
37
38        int lo = 1, hi = n;
39        while (lo < hi) {
40            int mid = lo + (hi - lo) / 2;
41
42            if (check(mid)) {
43                hi = mid;
44            } else {
45                lo = mid + 1;
46            }
47        }
48
49        return lo;
50    }
51};