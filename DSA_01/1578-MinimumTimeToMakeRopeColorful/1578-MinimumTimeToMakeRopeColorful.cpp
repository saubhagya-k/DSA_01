// Last updated: 08/09/2026, 11:35:05
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int n = colors.size();

        int time = 0;
        int preMax = 0;

        for(int i=0;i<n;i++){

            if(i>0 && colors[i]!= colors[i-1]){
                preMax = 0;
            }

            int curr = neededTime[i];

            time += min(preMax,curr);

            preMax = max(preMax,curr);

        }

        return time;
        
    }
};