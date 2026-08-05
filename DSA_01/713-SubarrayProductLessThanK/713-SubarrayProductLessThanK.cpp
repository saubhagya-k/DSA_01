// Last updated: 05/08/2026, 16:56:07
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        

        int n = nums.size();

        if(k<=1){
            return 0;
        }

        long long prod = 1;

        int left = 0;

        int count = 0;

        for(int i=0;i<n;i++){

            prod = prod*nums[i];

            while(prod>=k){
                prod = prod/nums[left];
                left++;
            }

            count += i-left+1;


        }
        return count;
    }
};