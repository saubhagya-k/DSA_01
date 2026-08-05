// Last updated: 05/08/2026, 17:02:00
class Solution {
public:
   
   void ans(vector<int>& nums,int start,vector<int>&path ,vector<vector<int>>&final){

    final.push_back(path);


    for(int i= start;i<nums.size();++i){

        // if(i>start){
        //     continue;
        // }

        path.push_back(nums[i]);

        ans(nums,i+1,path,final);

        path.pop_back();




    }
   }




    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>final;
        vector<int>path;

        sort(nums.begin(),nums.end());

        ans(nums,0,path,final);

        return final;




        
    }
};