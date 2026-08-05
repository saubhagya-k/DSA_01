// Last updated: 05/08/2026, 16:56:22
class Solution {
public:
    int maximumProduct(vector<int>& nums) {


        sort(nums.begin(),nums.end());

        int n = nums.size();

        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        
    }
};