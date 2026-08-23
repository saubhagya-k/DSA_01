// Last updated: 23/08/2026, 18:27:20
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();

        int left  = nums[0];
        int count = 1;
        int maxle = INT_MIN;
        int right = 0;

        if(n==1){
            return 1;
        }

        for(int i=1;i<n;i++){

            right = nums[i];

            if(right>left){
                count++;
            }

            else{
                count = 1;
            }

            left = right;

            maxle = max(maxle,count);

        }

        return maxle;
        
    }
};