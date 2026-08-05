// Last updated: 05/08/2026, 16:57:24
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        vector<int>final;

        for(int i=0;i<n;i++){
            index = abs(nums[i])-1;
           if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                index = i+1;

                final.push_back(index);

            }
            
        }

        return final;
        
    }
};