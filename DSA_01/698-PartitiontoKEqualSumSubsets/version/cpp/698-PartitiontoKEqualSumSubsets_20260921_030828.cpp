// Last updated: 21/09/2026, 03:08:28
1class Solution {
2public:
3
4int result = INT_MAX;
5
6void helper(vector<int>& cookies,int idx,vector<int>&children,int k ){
7
8    if(idx == cookies.size()){
9
10        int unfairness = *max_element(children.begin(),children.end());
11
12        result = min(result,unfairness);
13
14        return;
15
16
17    }
18
19    int cookie = cookies[idx];
20
21    for(int i=0;i<k;i++){
22        children[i]+=cookie;
23
24        helper(cookies,idx+1,children,k);
25
26        children[i]-=cookie;
27    }
28
29
30
31
32}
33    int distributeCookies(vector<int>& cookies, int k) {
34
35        vector<int>children(k,0);
36
37        helper(cookies,0,children,k);
38
39        return result;
40
41    
42
43        
44    }
45};