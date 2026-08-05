// Last updated: 05/08/2026, 16:59:01
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        long long sum = 0;

        int left = 0;

        int minP = INT_MAX;

        for(int right = 0;right<n;right++){
            sum += nums[right];

            while(sum>=target){

                minP = min(minP,right-left+1);
                sum = sum-nums[left];
                left++;

            }
        }

        return (minP==INT_MAX)?0:minP;



        
    }
};