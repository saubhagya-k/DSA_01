// Last updated: 05/08/2026, 16:53:03
class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        vector<int>final;
        int n = gain.size();
        final.push_back(0);

        int sum = 0;

        int b=0;


        for(int i=0;i<n;i++){

            sum = sum+gain[i];

            

            final.push_back(sum);

        }

        sort(final.begin(),final.end());

        b = final.back();


        return b;


        
        
    }
};