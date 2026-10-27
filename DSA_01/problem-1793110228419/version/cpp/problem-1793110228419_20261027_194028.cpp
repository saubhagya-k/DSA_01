// Last updated: 27/10/2026, 19:40:28
1class Solution {
2public:
3    int peakValleyDifference(vector<int>& nums) {
4
5        int n = nums.size();
6        vector<int>peaks;
7
8        vector<int>min_peak;
9
10        // since this problem contains searching all the peaks , so we will use here Linear Search O(N)
11
12        if(n==1){
13            peaks.push_back(nums[0]);
14            return 0;
15        }
16
17        for(int i=1;i<n-1;i++){
18
19            bool greatest_left = ( nums[i]>nums[i-1]);
20
21            bool greatest_right = ( nums[i]>nums[i+1]);
22
23            bool lower_left = ( nums[i]<nums[i-1]);
24
25            bool lower_right = ( nums[i]<nums[i+1]);
26
27            if(greatest_left && greatest_right){
28
29               peaks.push_back(nums[i]);
30                
31            }
32
33            if(lower_left && lower_right){
34                min_peak.push_back(nums[i]);
35            }
36        }
37
38        int maxpeak = 0;
39
40        int minpeak = 0;
41
42
43        for(int x:peaks){
44            maxpeak+=x;
45        }
46
47        for(int x : min_peak){
48
49            minpeak+=x;
50            
51        }
52
53
54        return maxpeak-minpeak;
55        
56    }
57};