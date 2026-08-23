// Last updated: 23/08/2026, 18:25:59
class Solution {
public:

int t[501][501];

int solve(int l,int r,vector<int>&prfi){

    if(l>=r){
        return 0;
    }

    if(t[l][r] !=-1){
        return t[l][r];
    }

    int score = 0;

    for(int mid = l; mid<=r-1 ; mid++){
        int leftSum = prfi[mid] - (l>0?prfi[l-1]:0);
        int rightSum = prfi[r] - prfi[mid+1-1];

        if(leftSum<rightSum){
            score = max(score,leftSum+solve(l,mid,prfi));
            }
        else if(leftSum>rightSum){
            score = max(score,rightSum+solve(mid+1,r,prfi));
        }    
        else{
            score = max({score,leftSum+solve(l,mid,prfi),rightSum+solve(mid+1,r,prfi)});
        }
    }

    return t[l][r] = score;

}
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int>prfi(n,0);

        prfi[0] = stoneValue[0];

        for(int i=1;i<n;i++){
            prfi[i] = prfi[i-1]+stoneValue[i];
        }

        memset(t,-1,sizeof(t));

        return solve(0,n-1,prfi);
        
    }
};