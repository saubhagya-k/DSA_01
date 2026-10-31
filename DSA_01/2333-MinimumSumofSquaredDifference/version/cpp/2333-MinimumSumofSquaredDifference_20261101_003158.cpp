// Last updated: 01/11/2026, 00:31:58
1class Solution {
2public:
3    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
4                               int k2) {
5        int n = nums1.size();
6        long long ans = 0;
7        int k = k1 + k2;
8        int maxDif = 0;
9        int res = 0;
10        for (int i = 0; i < n; i++) {
11            nums1[i] = abs(nums1[i] - nums2[i]);
12            maxDif = max(maxDif, nums1[i]);
13        }
14        int l = 0, r = maxDif;
15        auto check = [&](int mid) -> bool {
16            long long sum = 0;
17            for (int num : nums1) {
18                sum += num > mid ? num - mid : 0;
19            }
20            return sum <= k;
21        };
22        while (l <= r) {
23            int mid = (l + r) >> 1;
24            if (check(mid)) {
25                r = mid - 1;
26                res = mid;
27            } else {
28                l = mid + 1;
29            }
30        }
31        for (int i = 0; i < n; i++) {
32            if (nums1[i] > res) {
33                k -= (nums1[i] - res);
34            }
35        }
36        sort(nums1.begin(), nums1.end(), greater<int>());
37        for (int num : nums1) {
38            long long diff = res >= num ? num : res;
39            if (k && diff) {
40                diff--;
41                k--;
42            }
43            ans += diff * diff;
44        }
45        return ans;
46    }
47};