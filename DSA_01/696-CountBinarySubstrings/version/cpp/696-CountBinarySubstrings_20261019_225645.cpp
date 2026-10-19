// Last updated: 19/10/2026, 22:56:45
1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4
5        int prevCount = 0;
6
7        int currCount = 1;
8
9        int n = s.length();
10
11        int result = 0;
12
13
14        for(int i=1;i<n;i++){
15
16            if(s[i] == s[i-1]){
17                currCount++;
18            }
19
20            else{
21
22                result+=min(currCount,prevCount);
23
24                prevCount = currCount;
25
26                currCount = 1;
27                
28            }
29
30        }
31
32        return result + min(currCount,prevCount);
33        
34    }
35};