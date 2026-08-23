// Last updated: 23/08/2026, 18:24:15
1class Solution {
2public:
3    int repeatedStringMatch(string a, string b) {
4
5       
6        int count = 1;
7
8        string original_a = a;
9
10        while(a.length()<b.length()){
11            a+=original_a;
12            count++;
13        }
14
15        if(a.find(b) != string::npos){
16            return count;
17        }
18
19        a+=original_a;
20
21        if(a.find(b)!= string::npos){
22            return count+1;
23        }
24
25        return -1;
26        
27    }
28};