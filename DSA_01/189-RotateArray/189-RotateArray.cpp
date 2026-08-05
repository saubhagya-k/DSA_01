// Last updated: 05/08/2026, 16:59:29
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

       vector<int>hole;


     

      

        int size = nums.size();

          k = k % size;


        for(int i=size-k;i<size;i++){

            hole.push_back(nums[i]);

        }

        

        for(int i=0;i<size-k;i++){

            hole.push_back(nums[i]);
            
        }

        nums = hole;

        

        


        
    }
};