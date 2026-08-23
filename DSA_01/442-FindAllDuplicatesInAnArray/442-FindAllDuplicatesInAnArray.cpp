// Last updated: 23/08/2026, 18:28:22
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size();
        vector<int>final;

        unordered_map<int,int>map;

        for(int X :nums){
            map[X]++;
        }

        for(int i=0;i<n;i++){
            if(map[nums[i]]>=2){

                final.push_back(nums[i]);

                map[nums[i]]--;
                

            }
        }

        return final;
        
    }
};