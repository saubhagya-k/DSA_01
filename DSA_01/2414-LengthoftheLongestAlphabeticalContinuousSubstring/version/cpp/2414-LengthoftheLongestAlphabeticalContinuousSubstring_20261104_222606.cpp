// Last updated: 04/11/2026, 22:26:06
1class Solution {
2public:
3    int longestContinuousSubstring(string s) {
4
5        int n = s.length();
6
7        int count = 1;
8        int maxCount = INT_MIN;
9
10        if(n==1){
11            return 1;
12        }
13
14        int first = s[0]-'a';
15
16        for(int i=1;i<n;i++){
17
18            int second = s[i]-'a';
19
20            if(first+1 == second){
21
22                count++;
23
24                first = second;
25
26            }
27            else{
28                count = 1;
29                first = second;
30            }
31
32            maxCount = max(maxCount,count);
33        }
34
35        return maxCount;
36        
37    }
38};