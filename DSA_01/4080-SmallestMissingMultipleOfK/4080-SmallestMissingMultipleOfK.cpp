// Last updated: 27/08/2026, 12:50:39
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

       unordered_set<int>seen(nums.begin(),nums.end());

       int ans = k;

       while(seen.count(ans)){
         ans+=k;
       }

       return ans;



        
    }
};