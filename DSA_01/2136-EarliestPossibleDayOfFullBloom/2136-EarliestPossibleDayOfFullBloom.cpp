// Last updated: 08/09/2026, 11:33:58
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        int n = plantTime.size();

        vector<pair<int,int>> vec(n); //{plantTime,growTime}

        for(int i=0;i<n;i++){
            vec[i] = {plantTime[i],growTime[i]};
        }

        auto Lamda = [](pair<int,int>&P1,pair<int,int>&P2){
            return P1.second > P2.second;
        };

        sort(vec.begin(),vec.end(),Lamda);


        int maxBloomDays = 0;

        int prevplantDays = 0;

        for(int i=0;i<n;i++){
            int currPlantTime = vec[i].first;
            int currGrowTime = vec[i].second;

            prevplantDays += currPlantTime;

            int bloomingTime = prevplantDays+currGrowTime;

            maxBloomDays = max(maxBloomDays,bloomingTime);
        }


        return maxBloomDays;
        
    }
};