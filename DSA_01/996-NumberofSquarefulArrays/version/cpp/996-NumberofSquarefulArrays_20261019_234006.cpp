// Last updated: 19/10/2026, 23:40:06
1class Solution {
2public:
3int totalValidCount = 0;
4
5
6 void helperRecursion(int lastNum, int count, vector<int>& nums, vector<bool>& visited){
7
8    if (count == nums.size()) {
9            totalValidCount++;
10            return;
11        }
12
13    for (int i = 0; i < nums.size(); i++) {
14
15         if (visited[i]) continue;
16
17         if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
18
19
20         int sum = lastNum + nums[i];
21
22          int root = sqrt(sum);
23
24           if (root * root == sum) { 
25                visited[i] = true; 
26
27                 helperRecursion(nums[i], count + 1, nums, visited); 
28
29                visited[i] = false; 
30
31           }
32    }
33
34
35
36
37}
38    int numSquarefulPerms(vector<int>& nums) {
39
40        int n = nums.size();
41
42        vector<bool> visited(n, false);
43
44        sort(nums.begin(),nums.end());
45
46        for(int i=0;i<n;i++){
47
48            if (i > 0 && nums[i] == nums[i - 1]) continue;
49
50             visited[i] = true;
51             helperRecursion(nums[i],1,nums,visited);
52
53             visited[i] = false;
54        }
55
56        return  totalValidCount ;
57        
58    }
59};