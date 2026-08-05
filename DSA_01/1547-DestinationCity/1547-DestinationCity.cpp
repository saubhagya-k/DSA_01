// Last updated: 05/08/2026, 16:53:24
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

         unordered_set<string> startCities;


        for(auto &p :paths){
            startCities.insert(p[0]);
        }


        for (auto &p : paths) {
            if (startCities.find(p[1]) == startCities.end()) {
                return p[1];
            }
        }

         return "";



        
    }
};