// Last updated: 14/08/2026, 18:48:18
// think logically and do practically , you will get it , and do't try to do the same thing , every where, every question is beautiful and , can be solved by the different answers
1class Solution {
2public:
3    int maximumLengthSubstring(string s) {
4
5        int n = s.length();
6
7        int start = 0;
8
9        int mls = INT_MIN;
10
11        int end = 0;
12
13        if(n == 0) return 0;
14
15        int arr[26] = {0};
16
17       int j = 0;
18
19       for(int i=0;i<n;i++){
20        arr[s[i]-'a']++;
21
22        while(arr[s[i]-'a']>2){
23            arr[s[j]-'a']--;
24            j++;
25        }
26        mls = max(mls,i-j+1);
27       }
28
29       return mls;
30
31
32       
33       
34
35        
36    }
37};