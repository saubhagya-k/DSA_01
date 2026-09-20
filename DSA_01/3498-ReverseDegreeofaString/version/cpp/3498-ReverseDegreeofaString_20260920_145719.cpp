// Last updated: 20/09/2026, 14:57:19
1class Solution {
2public:
3    int reverseDegree(string s) {
4
5        int n = s.length();
6
7        int final = 0;
8
9        for(int i=0;i<n;i++){
10            int curr = s[i]-'a'+1;
11
12            int rev = 27-curr;
13
14            int currindex = i+1;
15
16            final+=rev*currindex;
17            
18        }
19        
20        return final;
21    }
22};