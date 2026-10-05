// Last updated: 05/10/2026, 21:24:29
1class Solution {
2public:
3    string reverseVowels(string s) {
4
5        int n = s.length();
6
7        vector<char>vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
8
9        int i = 0;
10        int j = n-1;
11
12        while(i<j){
13
14            if(find(vowel.begin(),vowel.end(),s[i])==vowel.end()){
15
16                i++;
17                continue;
18
19            }
20            if(find(vowel.begin(),vowel.end(),s[j])==vowel.end()){
21
22                j--;
23                continue;
24
25            }
26
27            char temp = s[i];
28            s[i] = s[j];
29            s[j] = temp;
30
31            i++;
32            j--;
33
34
35
36        }
37
38        return s;
39        
40    }
41};