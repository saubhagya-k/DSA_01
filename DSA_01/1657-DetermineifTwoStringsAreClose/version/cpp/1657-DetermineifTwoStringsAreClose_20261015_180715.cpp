// Last updated: 15/10/2026, 18:07:15
1class Solution {
2public:
3    bool closeStrings(string word1, string word2) {
4
5       vector<int>freq1(26,0);
6       vector<int>freq2(26,0);
7
8       int n = word1.length();
9       int m = word2.length();
10
11       if(n!=m){
12        return false;
13       }
14
15
16        for(char c : word1){
17            freq1[c - 'a']++;
18        }
19
20         for(char c : word2){
21            freq2[c - 'a']++;
22        }
23
24
25
26        for(int i=0;i<26;i++){
27            if(freq1[i]!=0 && freq2[i]!=0){
28                continue;
29            }
30            if(freq1[i]==0 && freq2[i]==0){
31                continue;
32            }
33
34            return false;
35        }
36
37        sort(freq1.begin(),freq1.end());
38
39        sort(freq2.begin(),freq2.end());
40
41
42
43
44        for(int i=0;i<26;i++){
45            if(freq1[i]!=freq2[i]){
46                return false;
47            }
48        }
49
50        return true;
51
52
53
54
55        
56    }
57};