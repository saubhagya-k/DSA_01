// Last updated: 26/08/2026, 20:13:49
1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4
5        int n = s.length();
6
7        int left = 0;
8        int right = 0;
9
10        int count_one = 0;
11
12        int min_length = n+1;
13
14        string ans = "";
15
16        while(right<n){
17            if(s[right] == '1'){
18                count_one++;
19            }
20
21            while(count_one == k){
22                int len = right-left+1;
23                string ok = s.substr(left,len);
24
25                if(len<min_length){
26                    min_length = len;
27
28                    ans = ok;
29                    }
30
31                    else if(len == min_length){
32                        if(ans== "" || ok<ans){
33                            ans = ok;
34                        }
35                    }
36
37                    if(s[left]=='1'){
38                        count_one--;
39                    }
40
41                    left++;
42            
43            }
44            right++;
45        }
46
47        return ans;
48
49    }
50};