// Last updated: 17/10/2026, 17:40:47
1class Solution {
2public:
3
4vector<int> getLeftHeight(vector<int>& height,int& n){
5
6    vector<int>leftmax(n,0);
7
8    leftmax[0] = height[0];
9
10    for(int i=1;i<n;i++){
11        leftmax[i] = max(leftmax[i-1],height[i]);
12    }
13
14    return leftmax;
15
16}
17
18
19vector<int> getRightHeight(vector<int>& height,int& n){
20
21    vector<int>Rightmax(n,0);
22
23    Rightmax[n-1] = height[n-1];
24
25    for(int i=n-2;i>=0;i--){
26        Rightmax[i] = max(Rightmax[i+1],height[i]);
27    }
28
29    return Rightmax;
30
31}
32
33    int trap(vector<int>& height) {
34
35        int n = height.size();
36
37        vector<int>leftmax = getLeftHeight(height,n);
38        vector<int>rightmax = getRightHeight(height,n);
39
40        int sum  = 0;
41
42        for(int i=0;i<n;i++){
43            int mini = min(leftmax[i],rightmax[i]);
44
45            int originalheight = mini-height[i];
46
47            sum+=originalheight;
48        }
49
50        return sum;
51
52
53        
54    }
55};