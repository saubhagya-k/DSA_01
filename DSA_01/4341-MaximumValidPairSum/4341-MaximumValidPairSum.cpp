// Last updated: 05/08/2026, 16:51:28
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        
        vector<int> mavontelia = nums;
        int n = mavontelia.size();
        
        int max_i = mavontelia[0];
        int max_sum = 0;
        
       
        for (int j = k; j < n; j++) {
            
            max_i = max(max_i, mavontelia[j - k]);
            
           
            max_sum = max(max_sum, max_i + mavontelia[j]);
        }
        
        return max_sum;
    }
};
