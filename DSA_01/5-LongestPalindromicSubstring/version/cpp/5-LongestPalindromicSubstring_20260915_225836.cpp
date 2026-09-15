// Last updated: 15/09/2026, 22:58:36
1class Solution {
2public:
3
4bool isPalendrome(string& s,int start,int end){
5
6    while(start<end){
7        if(s[start]!=s[end]) return false;
8
9        start++;
10        end--;
11    }
12
13    return true;
14
15
16}
17void makeit(string& s,vector<vector<string>>&final,vector<string>&curr,int start){
18
19    int n = s.length();
20
21    if(start == n){
22        final.push_back(curr);
23        return;
24    }
25
26    for(int end = start;end<n;end++){
27        if(isPalendrome(s,start,end)){
28
29
30            string substring = s.substr(start,end-start+1);
31            curr.push_back(substring);
32
33
34            makeit(s,final,curr,end+1);
35
36
37            curr.pop_back();
38
39
40
41
42
43        }
44    }
45
46}
47    vector<vector<string>> partition(string s) {
48
49        vector<vector<string>>final;
50        vector<string>curr;
51
52        int start = 0;
53
54         makeit(s,final,curr,start);
55
56
57         return final;
58
59
60        
61    }
62};