// Last updated: 05/08/2026, 17:02:39
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currsum = 0;
        int maxsum = nums[0];

        for(int num:nums){
            currsum += num;


            maxsum = max(maxsum,currsum);

            if(currsum<0){
                currsum = 0;
            }


        }

        return maxsum;

        
        
    }
};