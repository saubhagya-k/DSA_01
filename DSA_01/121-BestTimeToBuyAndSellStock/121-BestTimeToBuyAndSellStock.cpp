// Last updated: 05/08/2026, 17:00:54
class Solution {
public:
    int maxProfit(vector<int>& prices) {


        int profit = 0;
        int minProfit = prices[0];

        int size = prices.size();

        int maxProfit = 0;

        for(int i=1;i<size;i++){
            if(prices[i]<minProfit){
                minProfit = prices[i];
            }

            maxProfit = max(maxProfit,prices[i]-minProfit);

        }

        return maxProfit;
        
    }
};