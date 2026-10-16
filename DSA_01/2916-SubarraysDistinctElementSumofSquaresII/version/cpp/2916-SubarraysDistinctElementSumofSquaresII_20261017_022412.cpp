// Last updated: 17/10/2026, 02:24:12
1class BIT {
2public:
3    int size;
4    vector<long long> _tree1;
5    vector<long long> _tree2;
6
7    BIT(int n) {
8        size = n;
9        _tree1.assign(n + 2, 0);
10        _tree2.assign(n + 2, 0);
11    }
12
13    int _lowbit(int index) { return index & -index; }
14
15    void add(int left, int right, int delta) {
16        _add(left, delta);
17        _add(right + 1, -delta);
18    }
19
20    long long query(int left, int right) {
21        return _query(right) - _query(left - 1);
22    }
23
24private:
25    void _add(int index, int delta) {
26        index += 1;
27        long long rawIndex = index;
28        while (index <= size) {
29            _tree1[index] += delta;
30            _tree2[index] += rawIndex * delta;
31            index += _lowbit(index);
32        }
33    }
34
35    long long _query(int index) {
36        index += 1;
37        long long rawIndex = index + 1;
38        if (index > size) {
39            index = size;
40        }
41        long long res = 0;
42        while (index > 0) {
43            res += rawIndex * _tree1[index] - _tree2[index];
44            index -= _lowbit(index);
45        }
46        return res;
47    }
48};
49
50class Solution {
51public:
52    int sumCounts(vector<int>& A) {
53        int n = A.size();
54        long long res = 0, cur = 0;
55        BIT bit(n + 10);
56        unordered_map<int, int> seen;
57        long long mod = 1e9 + 7;
58        for (int i = 0; i < n; i++) {
59            int a = A[i];
60            int j = (seen.count(a) ? seen[a] : -1) + 1;
61            long long q = bit.query(j, i);
62            cur = (cur + q * 2 + i - j + 1) % mod;
63            res = (res + cur) % mod;
64            bit.add(j, i, 1);
65            seen[a] = i;
66        }
67        return res;
68    }
69};