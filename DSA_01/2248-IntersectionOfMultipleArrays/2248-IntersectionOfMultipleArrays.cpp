// Last updated: 08/09/2026, 11:33:51
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {

        unordered_set<int>lala(nums[0].begin(),nums[0].end());

        int size = nums.size();

        for(int i=1;i<size;i++){
            unordered_set<int>haha;
            for(int j=0;j<nums[i].size();j++){

                if(lala.find(nums[i][j])!=lala.end()){
                    haha.insert(nums[i][j]);
                }

            }
            lala = haha;
        }

        vector<int>ans(lala.begin(),lala.end());

        sort(ans.begin(),ans.end());

        return ans;
        
    }
};