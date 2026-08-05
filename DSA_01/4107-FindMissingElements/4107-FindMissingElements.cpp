// Last updated: 05/08/2026, 16:51:38
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        if (nums.empty()) return {};

        sort(nums.begin(),nums.end());

        vector<int>final;

        int total_element = nums.size();

        

        int a = nums[0];
        int b = nums[total_element-1];

        int n = b-a;

        for(int i=0;i<n;i++){

           if((find(nums.begin(), nums.end(), a + i) == nums.end()) && a <= b) {
               final.push_back(a + i);
            }


        }

        return final;


        
    }
};