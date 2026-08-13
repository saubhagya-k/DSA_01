// Last updated: 13/08/2026, 10:58:53
class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        vector<int>final;

        final.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                final.push_back(nums[i]);
            }


            else{

                break;

            }
           
            
            

        }

        int sum  = accumulate(final.begin(), final.end(), 0);

        for(int i=0;i<n;i++){
            if(find(nums.begin(), nums.end(), sum) != nums.end()){
                sum = sum+1;
               
            }
            
             
            
        }


        return sum;

       

        
    }
};