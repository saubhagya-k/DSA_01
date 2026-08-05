// Last updated: 05/08/2026, 17:00:08
class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = n-1;

        while(i<j){

            int mid = i+(j-i)/2;

            if(nums[mid]<=nums[j]){
                j = mid;

            }

            else{
                i = mid+1;
            }

        }
        return nums[j];
        
    }
};