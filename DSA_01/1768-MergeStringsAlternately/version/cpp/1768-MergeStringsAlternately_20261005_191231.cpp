// Last updated: 05/10/2026, 19:12:31
1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4
5        string result = "";
6        int n = word1.length();
7        int m = word2.length();
8
9
10        for(int i=0;i<max(n,m);i++){
11
12            if(i<n){
13                result+=word1[i];
14            }
15            if(i<m){
16                result+=word2[i];
17            }
18        }
19        
20        return result;
21    }
22};