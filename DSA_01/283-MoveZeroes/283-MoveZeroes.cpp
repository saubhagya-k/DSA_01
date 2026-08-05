// Last updated: 05/08/2026, 16:58:17
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int j=0, i;
    
    
    for(i=0;i<n;i++)
    {
        if(nums[i]!=0 && nums[j]==0)
            {
             swap(nums[i],nums[j]);
            }
        if(nums[j]!=0)
            j+=1;
    }
 


        
    }
};