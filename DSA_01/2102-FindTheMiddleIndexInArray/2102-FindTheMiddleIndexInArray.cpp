// Last updated: 01/09/2026, 16:19:24
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int n = nums.size();

        int total = 0;

        int rightSum = 0;
        int leftSum = 0;

        for(int i=0;i<n;i++){

            total += nums[i];

        }

        int j=0;

        for(int i=0;i<n;i++){

            rightSum = total-nums[i]-leftSum;

            if(rightSum == leftSum){
                return i;
            }

            leftSum += nums[i];

            

        }
        return -1;
    }
};