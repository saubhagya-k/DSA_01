// Last updated: 27/08/2026, 12:51:33
class Solution {
public:

int n;

vector<int> dp; 


    int stoneGameVIII(vector<int>& stones) {

         n = stones.size();

        vector<int> prefix(n);

        dp.assign(n,-1e9);

        prefix[0] = stones[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+stones[i];
        }

       return solve(prefix,1);


        
    }

    int solve(vector<int>&prefix,int i){

    if(i==n-1){

       return prefix[n-1];

    }

    if(dp[i]!=-1e9){
        return dp[i];
    }

    int nexstep = solve(prefix,i+1);


    int take = prefix[i] - nexstep;

    int skip = nexstep;


    return dp[i] = max(take,skip);
}
};