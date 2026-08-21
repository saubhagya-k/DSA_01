// Last updated: 21/08/2026, 23:08:06
1class Solution {
2public:
3    using ll = long long;
4    long long findKthSmallest(vector<int>& coins, int k) {
5        int n = coins.size();
6        int m = (1 << n);
7        sort(coins.begin(), coins.end());
8        vector<int> bit_count(m);
9        vector<ll> lcm(m);
10        ll l = k, r = 1ll * coins[0] * k + 1;
11
12        for (int mask = 1; mask < m; mask++) {
13            ll cur_lcm = 1;
14            for (int i = 0; i < n; i++) {
15                if (mask >> i & 1) {
16                    ll tmp = cur_lcm / gcd(cur_lcm, coins[i]);
17                    if (tmp <= r / coins[i]) {
18                        cur_lcm = tmp * coins[i];
19                    } else {
20                        cur_lcm = r + 1;
21                        break;
22                    }
23                    bit_count[mask]++;
24                }
25            }
26            lcm[mask] = cur_lcm;
27        }
28
29        auto get = [&](ll x) -> ll {
30            ll count = 0;
31            for (int mask = 1; mask < m; mask++) {
32                if (lcm[mask] > x) {
33                    continue;
34                }
35                if (bit_count[mask] & 1) {
36                    count += x / lcm[mask];
37                } else {
38                    count -= x / lcm[mask];
39                }
40            }
41            return count;
42        };
43
44        while (l < r) {
45            ll x = (l + r) >> 1;
46            if (get(x) >= k) {
47                r = x;
48            } else {
49                l = x + 1;
50            }
51        }
52        return l;
53    }
54};