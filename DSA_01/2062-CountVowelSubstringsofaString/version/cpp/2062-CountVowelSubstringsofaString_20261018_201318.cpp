// Last updated: 18/10/2026, 20:13:18
1class Solution {
2public:
3
4
5bool isVovel(char ch ){
6
7    return ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
8
9}
10    int countVowelSubstrings(string word) {
11
12        int n = word.length();
13
14        int count = 0;
15
16
17       
18
19        for(int i=0;i<n;i++){
20
21            unordered_set<char>set;
22
23
24            for(int j=i;j<n;j++){
25                if(!isVovel(word[j])){
26                    break;
27                }
28
29
30                set.insert(word[j]);
31
32                if(set.size() == 5){
33                    count++;
34                }
35            }
36
37
38
39        }
40
41        return count;
42        
43    }
44};