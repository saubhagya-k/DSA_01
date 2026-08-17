// Last updated: 17/08/2026, 11:56:41
1class Solution {
2public:
3
4int t[501][501];
5
6int solve(int l,int r,vector<int>&prfi){
7
8    if(l>=r){
9        return 0;
10    }
11
12    if(t[l][r] !=-1){
13        return t[l][r];
14    }
15
16    int score = 0;
17
18    for(int mid = l; mid<=r-1 ; mid++){
19        int leftSum = prfi[mid] - (l>0?prfi[l-1]:0);
20        int rightSum = prfi[r] - prfi[mid+1-1];
21
22        if(leftSum<rightSum){
23            score = max(score,leftSum+solve(l,mid,prfi));
24            }
25        else if(leftSum>rightSum){
26            score = max(score,rightSum+solve(mid+1,r,prfi));
27        }    
28        else{
29            score = max({score,leftSum+solve(l,mid,prfi),rightSum+solve(mid+1,r,prfi)});
30        }
31    }
32
33    return t[l][r] = score;
34
35}
36    int stoneGameV(vector<int>& stoneValue) {
37
38        int n = stoneValue.size();
39
40        vector<int>prfi(n,0);
41
42        prfi[0] = stoneValue[0];
43
44        for(int i=1;i<n;i++){
45            prfi[i] = prfi[i-1]+stoneValue[i];
46        }
47
48        memset(t,-1,sizeof(t));
49
50        return solve(0,n-1,prfi);
51        
52    }
53};