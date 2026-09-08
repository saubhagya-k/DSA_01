// Last updated: 08/09/2026, 11:32:57
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();

       int left = 0;
       int right = 0;

   
        int lls =  INT_MIN;

       unordered_map<int,int>map;


       for(int right=0;right<n;right++){

        map[nums[right]]++;


        while(map[nums[right]]>k){

            map[nums[left]]--;

            left++;

        }

         lls = max(lls,right-left+1);

       }

       return lls;


    }
};