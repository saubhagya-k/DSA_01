# Last updated: 23/08/2026, 18:24:35
from typing import List

class Solution:
    def elevatorRequests(self, n: int, start: int, requests: List[int]) -> int:
       
        left = [x for x in requests if x < start]
        right = [x for x in requests if x > start]
        
        left.sort(reverse=True)
        right.sort()
        
        L, R = len(left), len(right)
        if L == 0 and R == 0:
            return 0
            
        INF = 10**18
        
        dp = [[[INF, INF] for _ in range(R + 1)] for _ in range(L + 1)]
        
        total_elements = L + R
        
        if L > 0:
            dp[1][0][0] = (start - left[0]) * total_elements
        if R > 0:
            dp[0][1][1] = (right[0] - start) * total_elements
            
        for i in range(L + 1):
            for j in range(R + 1):
                for side in (0, 1):
                    cur_penalty = dp[i][j][side]
                    if cur_penalty >= INF:
                        continue
                        
                    remaining_requests = total_elements - (i + j)
                    if remaining_requests == 0:
                        continue
                        
                    if side == 0:
                        cur_pos = left[i - 1]
                    else:
                        cur_pos = right[j - 1]
                        
                    if i < L:
                        nxt_pos = left[i]
                        distance = cur_pos - nxt_pos
                        new_penalty = cur_penalty + distance * remaining_requests
                        if new_penalty < dp[i + 1][j][0]:
                            dp[i + 1][j][0] = new_penalty
                            
                    if j < R:
                        nxt_pos = right[j]
                        distance = nxt_pos - cur_pos
                        new_penalty = cur_penalty + distance * remaining_requests
                        if new_penalty < dp[i][j + 1][1]:
                            dp[i][j + 1][1] = new_penalty
                            
        return min(dp[L][R][0], dp[L][R][1])
