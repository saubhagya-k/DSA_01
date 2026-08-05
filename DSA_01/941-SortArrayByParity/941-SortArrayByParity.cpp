// Last updated: 05/08/2026, 16:55:06
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int n = nums.size();
        int i=0;

        vector<int>v;

        for(int j=0;j<n;j++){
            if(nums[j]%2 == 0){
                nums[i] = nums[j];
                i++;
            }
            else{
                v.push_back(nums[j]);
            }
            

        }
        for(int k=0;k<v.size();k++){
            nums[i] = v[k];
            i++;
        }

       
        return nums;
        
    }
};