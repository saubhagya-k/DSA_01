// Last updated: 13/08/2026, 11:01:44
class Solution {
public:

int t[101];

int solve(vector<int>& nums,int start,int end){

    if(start>end){
        return 0;
    }

    if(t[start]!=-1){
        return t[start];
    }

    int take = nums[start]+solve(nums,start+2,end);

    int skip = solve(nums,start+1,end);

    return t[start] = max(take,skip);

}
    int rob(vector<int>& nums) {

        int  n = nums.size();

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0],nums[1]);
        }

        memset(t,-1,sizeof(t));

        
        int take_index_0 = solve(nums,0,n-2);

         memset(t,-1,sizeof(t));


        int take_1_index = solve(nums,1,n-1);


        return max(take_index_0,take_1_index);
        
    }
};