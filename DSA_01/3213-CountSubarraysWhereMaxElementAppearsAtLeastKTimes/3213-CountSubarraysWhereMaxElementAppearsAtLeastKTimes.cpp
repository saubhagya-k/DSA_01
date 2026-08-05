// Last updated: 05/08/2026, 16:52:12
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {


    int max_ele = *max_element(nums.begin(),nums.end());

    int left = 0;
    long long total = 0;
    int count = 0;

    for(int right = 0;right<nums.size();right++){
        if(nums[right] == max_ele){

            count++;

        }

        while(count == k){
            if(nums[left] == max_ele){
                count--;
            }
            left++;
        }

        total +=left;
    }

    return total;

   

        
    }
};