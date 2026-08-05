// Last updated: 05/08/2026, 16:56:15
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        double avgMax = 0;

        

        double avg = 0;

        for(int i= 0;i<k;i++){

            avg += nums[i];
            }

            avgMax = avg;

        for(int i=k;i<n;i++){
            avg  = avg+nums[i] - nums[i-k];

            avgMax = max(avgMax,avg);
        }


        return avgMax/k;

        
        
    }



};