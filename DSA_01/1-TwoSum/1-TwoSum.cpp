// Last updated: 05/08/2026, 17:03:30
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

      

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
               if(nums[i]+nums[j]==target){
                return {i,j};
               }
            }
           
        }
         return {};
    }


        
    
};