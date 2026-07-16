class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int leftSum = 0;
        int rightSum = 0;

        int totalSum = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        for(int i=0;i<n;i++){
            rightSum = totalSum-leftSum-nums[i];

            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];

        }
        return -1;
        
    }
};