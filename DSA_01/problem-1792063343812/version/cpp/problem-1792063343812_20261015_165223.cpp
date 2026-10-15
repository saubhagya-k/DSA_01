// Last updated: 15/10/2026, 16:52:23
1class Solution {
2public:
3    bool halvesAreAlike(string s) {
4
5        int n = s.length();
6
7        int mid = n/2;
8
9        string a = s.substr(0,mid);
10
11        string b = s.substr(mid);
12
13        string vowels = "aeiouAEIOU";
14
15        int count_a = 0;
16        int count_b = 0;
17
18        for(char c : a){
19            if(vowels.find(c)!= string::npos){
20
21                count_a++;
22
23            }
24        }
25
26         for(char c : b){
27            if(vowels.find(c)!= string::npos){
28
29                count_b++;
30
31            }
32        }
33
34        if(count_a==count_b){
35            return true;
36        }
37
38
39        return false;
40        
41    }
42};