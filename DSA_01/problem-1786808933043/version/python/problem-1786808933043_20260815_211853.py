# Last updated: 15/08/2026, 21:18:53
1from typing import List
2
3class Solution:
4    def elevatorRequests(self, n: int, start: int, requests: List[int]) -> int:
5       
6        left = [x for x in requests if x < start]
7        right = [x for x in requests if x > start]
8        
9        left.sort(reverse=True)
10        right.sort()
11        
12        L, R = len(left), len(right)
13        if L == 0 and R == 0:
14            return 0
15            
16        INF = 10**18
17        
18        dp = [[[INF, INF] for _ in range(R + 1)] for _ in range(L + 1)]
19        
20        total_elements = L + R
21        
22        if L > 0:
23            dp[1][0][0] = (start - left[0]) * total_elements
24        if R > 0:
25            dp[0][1][1] = (right[0] - start) * total_elements
26            
27        for i in range(L + 1):
28            for j in range(R + 1):
29                for side in (0, 1):
30                    cur_penalty = dp[i][j][side]
31                    if cur_penalty >= INF:
32                        continue
33                        
34                    remaining_requests = total_elements - (i + j)
35                    if remaining_requests == 0:
36                        continue
37                        
38                    if side == 0:
39                        cur_pos = left[i - 1]
40                    else:
41                        cur_pos = right[j - 1]
42                        
43                    if i < L:
44                        nxt_pos = left[i]
45                        distance = cur_pos - nxt_pos
46                        new_penalty = cur_penalty + distance * remaining_requests
47                        if new_penalty < dp[i + 1][j][0]:
48                            dp[i + 1][j][0] = new_penalty
49                            
50                    if j < R:
51                        nxt_pos = right[j]
52                        distance = nxt_pos - cur_pos
53                        new_penalty = cur_penalty + distance * remaining_requests
54                        if new_penalty < dp[i][j + 1][1]:
55                            dp[i][j + 1][1] = new_penalty
56                            
57        return min(dp[L][R][0], dp[L][R][1])
58