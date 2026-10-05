// Last updated: 05/10/2026, 19:07:58
1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4
5        int n = word1.length();
6
7        int m = word2.length();
8
9        string final = "";
10
11
12        if(n<m||n==m){
13            for(int i=0;i<n;i++){
14
15            final+=word1[i];
16            final+=word2[i];
17
18            }
19
20          
21        }
22        else{
23            for(int i=0;i<m;i++){
24
25            final+=word1[i];
26            final+=word2[i];
27
28            }
29
30          
31        }
32        
33        
34
35        if(n>m){
36            for(int i=m;i<n;i++){
37                final+=word1[i];
38            }
39        }
40        else{
41            for(int i=n;i<m;i++){
42                final+=word2[i];
43            }
44        }
45
46        return final;
47        
48    }
49};