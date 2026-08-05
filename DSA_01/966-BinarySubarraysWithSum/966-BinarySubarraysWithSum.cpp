// Last updated: 05/08/2026, 16:55:02
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int>m;

        int total = 0;

         int prefixSum = 0;

        m[0] = 1;

        for(int i=0;i<nums.size();i++){

            prefixSum += nums[i];

            if(m.count(prefixSum-goal)){

                total+=m[prefixSum-goal];

            }

            m[prefixSum]++;



        }
        return total;
    }
};