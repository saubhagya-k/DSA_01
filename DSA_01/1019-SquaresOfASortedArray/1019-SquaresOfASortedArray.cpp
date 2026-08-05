// Last updated: 05/08/2026, 16:54:47
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int size = nums.size();

        int left = 0;
        int right = size - 1;

        vector<int> result(size);

        for(int i = size - 1; i >= 0; i--) {

            int val;

            if(abs(nums[left]) > abs(nums[right])) {

                val = nums[left];
                left++;

            } else {

                val = nums[right];
                right--;
            }

            result[i] = val * val;
        }

        return result;
    }
};