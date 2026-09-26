// Last updated: 27/09/2026, 00:11:13
1class Solution {
2public:
3    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
4
5        int n = word1.size();
6        int m = word2.size();
7
8        string a = "";
9        string b = "";
10
11        for(int i=0;i<n;i++){
12
13            a+=word1[i];
14
15        }
16
17        for(int i=0;i<m;i++){
18            b+=word2[i];
19
20        }
21
22        if(a==b){
23            return true;
24        }
25
26        return false;
27        
28    }
29};