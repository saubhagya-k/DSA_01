// Last updated: 01/09/2026, 16:19:16
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int mini = INT_MAX;
        int minInd = 0;

        int maxi = INT_MIN;
        int maxInd = 0;

        for(int i=0;i<n;i++){

            if(nums[i]<mini){
                mini = nums[i];
                minInd = i;
            }
            
        }

        for(int i=0;i<n;i++){

            if(nums[i]>maxi){
                maxi = nums[i];
                maxInd = i;
            }

        }

        int leftIndex = min(minInd,maxInd);
        int rightIndex = max(minInd,maxInd);


        return min({leftIndex+1+n-rightIndex,rightIndex+1,n-leftIndex});
        
    }
};