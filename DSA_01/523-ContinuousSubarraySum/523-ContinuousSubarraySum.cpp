// Last updated: 05/08/2026, 16:57:06
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>mp;

        int total = 0;

        mp[0] = -1;

        for(int i=0;i<nums.size();i++){

            total+=nums[i];

            int rem = total%k;

            if(mp.count(rem)){
                if(i-mp[rem] >=2){
                    return true;
                }
            }
            else{
                mp[rem] = i;
            }

        }
        return false;
        
    }
};