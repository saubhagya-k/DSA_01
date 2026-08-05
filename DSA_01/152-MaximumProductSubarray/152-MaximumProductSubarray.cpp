// Last updated: 05/08/2026, 17:00:09
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int prefixSum = 1;

        int sufixSum = 1;

        int ans = nums[0];

        int size = nums.size();

        for(int i=0;i<size;i++){

            if(prefixSum == 0) prefixSum=1;

            if(sufixSum == 0) sufixSum = 1;
 
            prefixSum = prefixSum*nums[i];

            sufixSum *= nums[size-1-i];


            ans = max(ans,max(prefixSum,sufixSum));




        }

        return ans;


        
    }
};