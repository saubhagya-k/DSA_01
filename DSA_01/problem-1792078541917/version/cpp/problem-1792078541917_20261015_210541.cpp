// Last updated: 15/10/2026, 21:05:41
1class Solution {
2public:
3
4
5bool allCapital(string word){
6
7    for(char c: word){
8        if(c<'A'||c>'Z'){
9            return false;
10        }
11
12        
13    }
14    return true;
15
16}
17
18
19
20
21bool allSmall(string word){
22
23    for(char c: word){
24        if(c<'a'||c>'z'){
25            return false;
26        }
27
28       
29    }
30     return true;
31
32
33}
34
35    bool detectCapitalUse(string word) {
36
37        if(allCapital(word)||allSmall(word)||allSmall(word.substr(1))){
38            return true;
39        }
40
41        return false;
42        
43    }
44};