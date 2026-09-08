// Last updated: 08/09/2026, 11:38:06
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int>a(arr.begin(),arr.end());

        unordered_map<int,int>rank;

        int ranks = 1;


        for(int x:a){

            rank[x] = ranks++;

        }


        vector<int>ans;

        for(int y:arr){
            ans.push_back(rank[y]);
        }

        return ans;
        
    }
};