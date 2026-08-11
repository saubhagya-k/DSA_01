// Last updated: 11/08/2026, 20:23:23
1class Solution {
2public:
3    int missingInteger(vector<int>& nums) {
4
5        int n = nums.size();
6
7        vector<int>final;
8
9        final.push_back(nums[0]);
10
11        for(int i=1;i<n;i++){
12            if(nums[i] == nums[i-1]+1){
13                final.push_back(nums[i]);
14            }
15
16
17            else{
18
19                break;
20
21            }
22           
23            
24            
25
26        }
27
28        int sum  = accumulate(final.begin(), final.end(), 0);
29
30        for(int i=0;i<n;i++){
31            if(find(nums.begin(), nums.end(), sum) != nums.end()){
32                sum = sum+1;
33               
34            }
35            
36             
37            
38        }
39
40
41        return sum;
42
43       
44
45        
46    }
47};