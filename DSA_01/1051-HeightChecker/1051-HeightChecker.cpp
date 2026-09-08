// Last updated: 08/09/2026, 11:38:50
class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int>v;
        v=heights;

        int n = heights.size();
        int n1 = v.size();
        int i=0;
        int j=0;

        int count = 0;

        sort(v.begin(),v.end());

       while(i<n || j<n1){
        if(heights[i] != v[j]){
            count++;

        }
        i++;
        j++;
       }

       return count;

      


        
    }
};