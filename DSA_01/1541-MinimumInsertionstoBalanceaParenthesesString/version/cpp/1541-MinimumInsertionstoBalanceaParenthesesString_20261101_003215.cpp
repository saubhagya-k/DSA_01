// Last updated: 01/11/2026, 00:32:15
1class Solution {
2public:
3    int minInsertions(string s) {
4        int insertions = 0;
5        int leftCount = 0;
6        int length = s.size();
7        int index = 0;
8        while (index < length) {
9            char c = s[index];
10            if (c == '(') {
11                leftCount++;
12                index++;
13            } else {
14                if (leftCount > 0) {
15                    leftCount--;
16                } else {
17                    insertions++;
18                }
19                if (index < length - 1 && s[index + 1] == ')') {
20                    index += 2;
21                } else {
22                    insertions++;
23                    index++;
24                }
25            }
26        }
27        insertions += leftCount * 2;
28        return insertions;
29    }
30};