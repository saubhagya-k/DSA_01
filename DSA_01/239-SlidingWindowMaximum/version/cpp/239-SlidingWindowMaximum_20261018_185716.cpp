// Last updated: 18/10/2026, 18:57:16
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4
5        vector<int>final;
6
7        deque<int>dq;
8
9        int n = nums.size();
10
11        for(int i=0;i<n;i++){
12
13            if(!dq.empty()&& dq.front()<i-k+1){
14                dq.pop_front();
15            }
16
17            while(!dq.empty() && nums[dq.back()]<nums[i]){
18                dq.pop_back();
19            }
20
21            dq.push_back(i);
22
23            if(i>=k-1){
24                final.push_back(nums[dq.front()]);
25            }
26        }
27
28        return final;
29        
30    }
31};