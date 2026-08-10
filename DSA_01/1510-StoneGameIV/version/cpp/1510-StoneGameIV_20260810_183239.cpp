// Last updated: 10/08/2026, 18:32:39
1class Solution {
2public:
3    vector<int> t;
4
5    bool solve(int n) {
6        if (n == 0) {
7            return false;
8        }
9
10        if (t[n] != -1) {
11            return t[n] == 1; 
12        }
13        
14        for (int k = 1; k * k <= n; k++) {
15            if (solve(n - (k * k)) == false) {
16                
17                return t[n] = 1; 
18            }
19        }
20
21        return t[n] = 0;
22    }
23
24    bool winnerSquareGame(int n) {
25        t.assign(n + 1, -1);
26        return solve(n);
27    }
28};
29