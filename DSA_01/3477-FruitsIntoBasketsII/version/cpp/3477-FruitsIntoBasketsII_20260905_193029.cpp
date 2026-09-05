// Last updated: 05/09/2026, 19:30:29
1class Solution {
2public:
3void build(int i,int l,int r,vector<int>& baskets, vector<int>& segmentTree){
4
5    if(l==r){
6        segmentTree[i] = baskets[l];
7
8        return ;
9    }
10
11    int mid = l+(r-l)/2;
12
13    build(2*i+1,l,mid,baskets,segmentTree);
14    build(2*i+2,mid+1,r,baskets,segmentTree);
15
16
17    segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]);
18
19}
20    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
21
22        int n = fruits.size();
23
24        vector<int>segmentTree(4*n,-1);
25
26        build(0,0,n-1,baskets,segmentTree);
27
28
29        int unplaced = 0;
30        for(int &fruit:fruits){
31            if(querySegmentTree(0,0,n-1,segmentTree,fruit) == false){
32                unplaced++;
33            }
34        }
35
36        return unplaced;
37
38
39        
40    }
41        // 1. ADDED '&' to vector<int>& segmentTree
42    bool querySegmentTree(int i, int l, int r, vector<int>& segmentTree, int fruit) {
43        if (segmentTree[i] < fruit) {
44            return false;
45        }
46
47        if (l == r) {
48            segmentTree[i] = -1;
49            return true;
50        }
51
52        int mid = l + (r - l) / 2;
53        bool placed = false;
54
55        
56        if (segmentTree[2 * i + 1] >= fruit) {
57            placed = querySegmentTree(2 * i + 1, l, mid, segmentTree, fruit);
58        }
59        
60       
61        if (!placed && segmentTree[2 * i + 2] >= fruit) {
62            placed = querySegmentTree(2 * i + 2, mid + 1, r, segmentTree, fruit);
63        }
64
65        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
66        return placed;
67    }
68
69};