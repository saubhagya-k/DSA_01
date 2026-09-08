// Last updated: 08/09/2026, 12:13:51
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

     unordered_map<int,int>m;
     int total=0;
     int prefixSum = 0;
     int rem = 0;
     m[0]=1;

     for(int i=0;i<nums.size();i++){
        prefixSum+=nums[i];
        rem = prefixSum%k;

        if(rem<0){
            rem = rem+k;
        }
        if(m.count(rem)){
            total+=m[rem];
            m[rem]++;
        }
        else{
        m[rem] = 1;
        }
     }

     return total;
    }
    
};