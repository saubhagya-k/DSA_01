// Last updated: 18/09/2026, 01:52:19
1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4
5        int n = arr.size();
6
7        int i = 0;
8        int j = 0;
9
10        int currentSum = 0;
11        vector<int>minBest(n,INT_MAX);
12
13        int bestMINlen = INT_MAX;
14
15        int result = INT_MAX;
16
17        while(j<n){
18            currentSum+=arr[j];
19
20            while(i<j && currentSum>target){
21                currentSum-=arr[i++];
22            }
23
24            if(currentSum == target){
25                int len = j-i+1;
26
27
28                if(i>0 && minBest[i-1] != INT_MAX){
29
30                result = min(result,len+minBest[i-1]);
31
32                }
33
34                bestMINlen = min(bestMINlen,len);
35
36
37            }
38
39            minBest[j] = bestMINlen;
40            j++;
41        }
42
43        return result == INT_MAX?-1:result;
44
45        
46    }
47};