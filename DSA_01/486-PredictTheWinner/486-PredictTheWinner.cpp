// Last updated: 05/08/2026, 16:57:14
#include <vector>
#include <algorithm>

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        
        std::vector<int> dp = nums;

       
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                
                dp[i] = std::max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }

       
        return dp[0] >= 0;
    }
};
