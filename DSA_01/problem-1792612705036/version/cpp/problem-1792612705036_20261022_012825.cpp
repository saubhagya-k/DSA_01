// Last updated: 22/10/2026, 01:28:25
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4
5        priority_queue<int,vector<int>,greater<int>>minHeap;
6
7        for(int num : nums){
8            minHeap.push(num);
9            if(minHeap.size() > k){
10                minHeap.pop();
11            }
12        }
13
14        return minHeap.top();
15        
16    }
17};