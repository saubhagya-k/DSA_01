// Last updated: 05/08/2026, 16:52:09
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int,int>count;
        int start = 0;
        int end = 0;
        int len  = INT_MIN;
        int n = nums.size();

        while(end<n){
            count[nums[end]]++;

            while(count[nums[end]]>k){
                count[nums[start]]--;
                start++;
            }

            len = max(len,end-start+1);
            end++;

        }

        return len;
        
    }
};