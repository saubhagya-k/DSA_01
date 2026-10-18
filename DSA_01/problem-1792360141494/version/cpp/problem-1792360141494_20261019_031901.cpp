// Last updated: 19/10/2026, 03:19:01
1class Solution {
2public:
3    vector<int> partitionLabels(string s) {
4        int n = s.length();
5        vector<int> final_ans;
6        vector<int> mp(26, -1);
7
8        for(int i = 0; i < n; i++){
9            mp[s[i] - 'a'] = i;
10        }
11
12        // FIX: Use a while loop to prevent double-incrementing 'i'
13        int i = 0;
14        while(i < n){
15            int end = mp[s[i] - 'a'];
16            int j = i;
17
18            while(j < end){
19                end = max(end, mp[s[j] - 'a']);
20                j++;
21            }
22
23            final_ans.push_back(j - i + 1);
24            
25            // Correctly set 'i' to the beginning of the next chunk
26            i = j + 1;
27        }
28
29        return final_ans;
30    }
31};
32