// Last updated: 05/11/2026, 21:50:47
1class Solution {
2public:
3
4bool isVovel(char ch){
5
6return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u';
7
8}
9   
10 int maxVowels(string s, int k) {
11
12    int n = s.length();
13
14    int count = 0;
15    int maxCount = 0;
16
17    for(int i=0;i<k;i++){
18        if(isVovel(s[i])){
19            count++;
20        }
21    }
22
23    maxCount = max(maxCount,count);
24
25    for(int right = k;right<n;right++){
26
27        if(isVovel(s[right])){
28            count++;
29        }
30
31        if(isVovel(s[right-k])){
32            count--;
33        }
34
35        maxCount = max(maxCount,count);
36
37        if(maxCount == k) return k;
38    }
39
40    return maxCount;
41
42      
43        
44    }
45};