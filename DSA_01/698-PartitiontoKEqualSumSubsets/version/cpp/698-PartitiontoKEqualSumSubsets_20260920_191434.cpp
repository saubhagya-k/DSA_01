// Last updated: 20/09/2026, 19:14:34
1class Solution {
2public:
3
4bool backtrack(vector<int>& nums,vector<int>&visited,int start_index,int curr_bucketsum,int target,int k){
5
6    if(k==1){
7        return true;
8    }
9
10    if(curr_bucketsum==target){
11    
12        return backtrack(nums,visited,0,0,target,k-1);
13    }
14
15    for(int i = start_index ;i<nums.size();i++){
16        if(curr_bucketsum+nums[i]>target ||visited[i]==1){
17            continue;
18        }
19
20        visited[i] = 1;
21
22
23        if(backtrack(nums,visited,i+1,curr_bucketsum+nums[i],target,k)){
24            return true;
25        }
26
27        visited[i] = 0;
28    }
29
30
31
32
33
34
35    return false;
36
37
38
39}
40    bool canPartitionKSubsets(vector<int>& nums, int k) {
41
42        int n = nums.size();
43
44        int sum =0;
45
46        for(int i=0;i<n;i++){
47
48            sum+=nums[i];
49        }
50
51     
52
53        if(sum%k!=0){
54            return false;
55        }
56
57        int target = sum/k;
58
59        sort(nums.begin(),nums.end(),greater<int>());
60
61
62        if(nums[0]>target){
63            return false;
64        }
65
66
67        vector<int>visited(n,false);
68
69
70        // START THE DFS CALL HERE
71        // - start_index = 0 (Start looking from the beginning of nums)
72        // - current_sum = 0 (The first bucket starts completely empty)
73
74        return backtrack(nums,visited,0,0,target,k);
75
76        
77        
78    }
79};