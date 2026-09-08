// Last updated: 08/09/2026, 11:31:37
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