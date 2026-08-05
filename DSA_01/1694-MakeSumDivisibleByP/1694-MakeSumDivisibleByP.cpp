// Last updated: 05/08/2026, 16:53:11
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int totalRemoveSubarray = nums.size();

        unordered_map<int,int> m;
        long long prefixSum = 0;
        int rem = 0;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
        }

        rem = prefixSum % p;

        if(rem == 0){
            return 0;
        }

        
        prefixSum = 0;
        m[0] = -1;  

        for(int i = 0; i < nums.size(); i++){

            prefixSum += nums[i];
            int currMod = prefixSum % p;

            int target = (currMod - rem + p) % p;

            if(m.count(target)){
                totalRemoveSubarray = min(totalRemoveSubarray, i - m[target]);
            }

           
            m[currMod] = i;
        }

        if(totalRemoveSubarray == nums.size())
            return -1;

        return totalRemoveSubarray;
    }
};
