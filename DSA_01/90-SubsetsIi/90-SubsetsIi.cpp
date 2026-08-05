// Last updated: 05/08/2026, 17:01:52
class Solution {
public:

  void backtrack(vector<int>&nums,int start,vector<int>&path,vector<vector<int>>&final){

    final.push_back(path);

    for(int i=start;i<nums.size();++i){
        if(i > start && nums[i] == nums[i-1]){
            continue;
        }
        path.push_back(nums[i]);

        backtrack(nums,i+1,path,final);

        path.pop_back();
    }
  }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>>final;
        vector<int>path;

        sort(nums.begin(),nums.end());

        backtrack(nums,0,path,final);

        return final;

        
        
    }
};