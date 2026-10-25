// Last updated: 25/10/2026, 21:13:55
1class Solution {
2public:
3    string licenseKeyFormatting(string s, int k) {
4
5        string t = "";
6        int strCount = 0;
7
8        
9
10        for(char c: s){
11            if(c=='-'){
12                continue;
13            }
14            else{
15                t+=toupper(c);
16                strCount++;
17
18            }
19
20
21        }
22       
23
24        int n = t.length();
25
26        string result = "";
27
28        int count = 0;
29
30        for(int i=n-1;i>=0;i--){
31
32            result += t[i];
33
34            count++;
35
36            if(count == k && i>0){
37                result+='-';
38
39                count = 0;
40
41            }
42
43
44
45        }
46
47        reverse(result.begin(), result.end());
48
49
50        return result;
51
52
53
54        
55    }
56};