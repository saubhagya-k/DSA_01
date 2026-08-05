// Last updated: 05/08/2026, 16:58:53
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        

        unordered_map<int,int>maja;

        int size = nums.size();


        for(int i=0;i<size;i++){
            maja[nums[i]]++;
        }

        for(int i=0;i<size;i++){
            if(maja[nums[i]]>1){
                return true;
            }
            
        };
        return false;

    }


    
};