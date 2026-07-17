class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int first = 0;
        int second = 0;

        int n = cost.size();


        for(int i=2;i<=n;i++){
            int curr = min(first+cost[i-2],second+cost[i-1]);

            first = second;
            second = curr;
        }

        return second;
        
    }
};