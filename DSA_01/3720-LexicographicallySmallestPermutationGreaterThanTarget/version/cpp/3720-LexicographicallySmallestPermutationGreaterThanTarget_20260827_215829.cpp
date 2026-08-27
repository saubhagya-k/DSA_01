// Last updated: 27/08/2026, 21:58:29
1class Solution {
2public:
3
4string result = "";
5
6bool solve(string curr,vector<int>&count,string target, int i,bool greater){
7
8    if(i==target.length()){
9        if(greater){
10            result = curr;
11            return true;
12        }
13
14        return false;
15    }
16
17    for(char ch = 'a' ;ch<='z';ch++){
18        if(count[ch-'a'] == 0){
19            continue;
20        }
21        if(greater == false && ch<target[i]){
22            continue;
23        }
24
25        curr.push_back(ch);
26
27        count[ch-'a']--;
28
29        bool isGreater = greater || ch>target[i];
30
31        if(solve(curr,count,target,i+1,isGreater)){
32            return true;
33        }
34
35
36        curr.pop_back();
37        count[ch-'a']++;
38
39
40    }
41
42    return false;
43
44
45
46}
47    string lexGreaterPermutation(string s, string target) {
48
49        vector<int>count(26,0);
50
51        for(char X:s){
52            count[X-'a']++;
53        }
54
55        string curr;
56
57        solve(curr,count,target,0,false);
58
59        return result;
60        
61    }
62};