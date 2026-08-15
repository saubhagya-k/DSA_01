// Last updated: 15/08/2026, 20:39:17
1class Solution {
2public:
3    int minOperations(string s) {
4
5        string dorivexalu = s;
6
7        int n = dorivexalu.length();
8
9        int min_total_ops = 1e9;
10
11        string doubled = dorivexalu+dorivexalu;
12
13        for(int rot = 0;rot<n;rot++){
14            int inc = 0;
15            int left = rot;
16            int right = rot + n-1;
17
18            while(left<right){
19                char c1 = doubled[left];
20                char c2 = doubled[right];
21
22                if(c1 != c2){
23                    int diff = abs(c1-c2);
24
25                    inc += min(diff,26-diff);
26                }
27                left++;
28                right--;
29            }
30            min_total_ops = min(min_total_ops,rot+inc);
31        }
32        return min_total_ops;
33        
34        
35    }
36};