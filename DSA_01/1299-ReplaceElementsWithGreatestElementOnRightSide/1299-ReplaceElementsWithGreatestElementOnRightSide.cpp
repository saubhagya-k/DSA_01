// Last updated: 08/09/2026, 11:38:25
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n = arr.size();

        int m = -1;

        

        for(int i=n-1;i>=0;i--){

            int temp = arr[i];
            arr[i] = m;

            m = max(temp,m);

           

        


        }

        return arr;
    }
};