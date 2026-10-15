// Last updated: 15/10/2026, 22:44:31
1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        // String length.
5        int K = strs[0].size();
6        
7        // Variable to store the count of columns to be deleted.
8        int answer = 0;
9        // Iterate over each index in the string.
10        for (int col = 0; col < K; col++) {
11            // Iterate over the strings.
12            for (int row = 1; row < strs.size(); row++) {
13                // Characters should be in increasing order, 
14                // If not, increment the counter.
15                if (strs[row][col] < strs[row - 1][col]) {
16                    answer++;
17                    break;
18                }
19            }
20        }
21        
22        return answer;
23    }
24};