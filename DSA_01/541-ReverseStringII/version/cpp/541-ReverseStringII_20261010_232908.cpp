// Last updated: 10/10/2026, 23:29:08
1class Solution {
2public:
3    string reverseStr(string s, int k) {
4
5        int l = 0;
6
7        int r = min(k,(int)s.length());
8
9        while(l<s.length()){
10
11            reverse(s.begin()+l,s.begin()+r);
12
13            l +=2*k;
14            r = min(l+k,(int)s.length());
15
16        }
17
18        return s;
19        
20    }
21};