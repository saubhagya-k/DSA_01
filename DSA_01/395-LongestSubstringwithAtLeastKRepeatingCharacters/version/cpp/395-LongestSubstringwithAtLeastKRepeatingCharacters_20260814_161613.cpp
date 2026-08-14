// Last updated: 14/08/2026, 16:16:13
// some what tricky , better fallow this https://www.youtube.com/watch?v=bHZkCAcj3dc
1class Solution {
2public:
3    int longestSubstring(string s, int k) {
4
5
6        int n = s.length();
7
8        if(n==0 || n<k){
9            return 0;
10        }
11
12        if(k<=1){
13            return n;
14        }
15
16        unordered_map<char,int>map;
17
18        for(char X :s){
19            map[X]++;
20        }
21
22        int l = 0;
23
24        while(l<n && map[s[l]]>=k){
25            l++;
26        }
27
28        if(l>=n-1){
29            return l;
30        }
31
32        int l1 = longestSubstring(s.substr(0,l),k);
33        while(l<n && map[s[l]]<k){
34            l++;
35        }
36      int l2 =(l<n)? longestSubstring(s.substr(l),k):0;
37
38
39      return max(l1,l2);
40
41
42
43
44
45        
46    }
47};