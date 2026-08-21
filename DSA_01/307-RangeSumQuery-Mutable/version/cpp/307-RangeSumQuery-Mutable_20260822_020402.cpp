// Last updated: 22/08/2026, 02:04:02
1class NumArray {
2public:
3
4int n;
5vector<int>segmentTree;
6
7void buildSegmentTree(int i,int l,int r,vector<int>& nums){
8
9    if(l==r){
10        segmentTree[i] = nums[l];
11        return;
12    }
13
14    int mid = l+ (r-l)/2;
15
16    buildSegmentTree(2*i+1,l,mid,nums);
17    buildSegmentTree(2*i+2,mid+1,r,nums);
18
19    segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
20
21}
22
23void updateSgementTree(int index,int val,int i,int l,int r){
24
25    if(l==r){
26        segmentTree[i] = val;
27
28        return;
29    }
30
31    int mid =  l+(r-l)/2;
32
33    if(index<=mid){
34        updateSgementTree(index,val,2*i+1,l,mid);
35    }
36    else{
37        updateSgementTree(index,val,2*i+2,mid+1,r);
38    }
39
40    segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
41
42}
43
44int sumRangeSegmentTree(int left,int right,int i,int l,int r){
45
46
47    if(l>right || r<left){
48        return 0;
49    }
50
51    if(l>=left && r<=right){
52        return segmentTree[i];
53    }
54
55    int mid = l+(r-l)/2;
56
57    return sumRangeSegmentTree(left,right,2*i+1,l,mid)+sumRangeSegmentTree(left,right,2*i+2,mid+1,r);
58
59
60
61
62}
63    NumArray(vector<int>& nums) {
64
65        n = nums.size();
66
67        segmentTree.resize(4*n);
68        buildSegmentTree(0,0,n-1,nums);
69        
70    }
71    
72    void update(int index, int val) {
73        
74        updateSgementTree(index,val,0,0,n-1);
75    }
76    
77    int sumRange(int left, int right) {
78
79       return  sumRangeSegmentTree(left,right,0,0,n-1);
80        
81    }
82};
83
84/**
85 * Your NumArray object will be instantiated and called as such:
86 * NumArray* obj = new NumArray(nums);
87 * obj->update(index,val);
88 * int param_2 = obj->sumRange(left,right);
89 */