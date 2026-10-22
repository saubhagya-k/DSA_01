// Last updated: 22/10/2026, 10:30:00
1class Solution {
2public:
3    string kthLargestNumber(vector<string>& nums, int k) {
4
5        auto mycompare = [](const string& a,const string& b){
6            if(a.length()!=b.length()){
7                return a.length()>b.length();  // Shorter string has higher priority (goes to the top)
8            }
9            return a>b;
10        };
11        
12
13        sort(nums.begin(),nums.end(),mycompare);
14
15        return nums[k-1];
16    }
17};