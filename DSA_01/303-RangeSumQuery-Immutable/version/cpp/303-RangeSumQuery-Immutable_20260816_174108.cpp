// Last updated: 16/08/2026, 17:41:08
// you can also use here segment trees
1class NumArray {
2public:
3vector<int> prefixSums;
4    NumArray(vector<int>& nums) {
5        int n = nums.size();
6
7        prefixSums.resize(n+1,0);
8
9        for(int i=0;i<n;i++){
10           prefixSums[i+1] = prefixSums[i]+nums[i];
11        }
12        
13    }
14    
15    int sumRange(int left, int right) {
16
17        return (prefixSums[right+1]-prefixSums[left]);
18        
19    }
20};
21
22/**
23 * Your NumArray object will be instantiated and called as such:
24 * NumArray* obj = new NumArray(nums);
25 * int param_1 = obj->sumRange(left,right);
26 */