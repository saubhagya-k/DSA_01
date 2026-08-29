// Last updated: 29/08/2026, 13:52:44
1class Solution {
2public:
3char midChar = '$';
4int halfLen = 0;
5
6string result = "";
7
8bool solve(string &curr,vector<int>&count,string &target,int i,int greater){
9
10    if(curr.length() == halfLen){
11        string candidate = curr;
12        string right = curr;
13
14        reverse(begin(right),end(right));
15
16        if(midChar != '$'){
17            candidate += midChar;
18        }
19
20        candidate+=right;
21
22        if(candidate>target){
23            result = candidate;
24            return true;
25        }
26
27        return false;
28    }
29
30    for(char ch = 'a' ;ch<='z';ch++){
31        if(count[ch-'a']==0)  continue;
32
33        if(!greater && ch <target[i]){
34            continue;
35        }
36
37        curr.push_back(ch);
38        count[ch-'a']--;
39
40        bool isGreater = greater || ch>target[i];
41
42        if(solve(curr,count,target,i+1,isGreater)){
43            return true;
44        }
45
46        curr.pop_back();
47        count[ch-'a']++;
48    }
49
50    return false;
51}
52
53
54    string lexPalindromicPermutation(string s, string target) {
55
56        int n = s.length();
57
58        int odd_count = 0;
59
60        vector<int>count(26,0);
61
62        for(char X : s){
63            count[X-'a']++;
64        }
65
66        for(int i=0;i<26;i++){
67            if(count[i]%2 == 1){
68                odd_count++;
69
70                midChar = i+'a';
71            }
72        }
73
74        if(odd_count>1){
75            return "";
76        }
77
78        for(int i=0;i<26;i++){
79            count[i]/=2;
80        }
81
82        halfLen = n/2;
83
84        string curr = "";
85
86        solve(curr,count,target,0,false);
87
88        return result;
89        
90    }
91};