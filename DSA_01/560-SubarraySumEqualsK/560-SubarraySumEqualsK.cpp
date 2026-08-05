// Last updated: 05/08/2026, 16:56:47
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // int total = 0;


        // for(int i=0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j=i;j<nums.size();j++){

        //         sum += nums[j];

        //         if(sum == k){

        //             total++;

        //         }
        //     }
        // }

        // return total;

        unordered_map<int,int>m;

        //prefixSum,value

        int prefixSum = 0;

        m[0]=1;

        int total = 0;

        for(int i=0;i<nums.size();i++){

            prefixSum += nums[i];

            if(m.count(prefixSum-k) ){
                total+=m[prefixSum-k];
            }
            
                m[prefixSum]++;
            


        }

        return total;




        
    }
};