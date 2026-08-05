// Last updated: 05/08/2026, 16:57:03
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int size = nums.size();

        for(int i=0;i<size;i++){

            if(nums[i]==0){
                nums[i]=-1;
            }

        };

        unordered_map<int,int>mp;

        int prefixSum = 0;
        int maxi = 0;
        mp[0] = -1;

        for(int i = 0;i<size;i++){
            prefixSum += nums[i];

            if(mp.find(prefixSum) != mp.end()){
                int length = i-mp[prefixSum];

                maxi = max(maxi,length);
            }

            else {
                
                mp[prefixSum] = i;
            }


        }


        return maxi;
         







        
    }
};