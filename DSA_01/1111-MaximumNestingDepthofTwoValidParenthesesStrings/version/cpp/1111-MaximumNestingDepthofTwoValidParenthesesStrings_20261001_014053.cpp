// Last updated: 01/10/2026, 01:40:53
1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4        int d = 0;
5        vector<int> ans;
6        for (char& c : seq)
7            if (c == '(') {
8                ++d;
9                ans.push_back(d % 2);
10            } else {
11                ans.push_back(d % 2);
12                --d;
13            }
14        return ans;
15    }
16};