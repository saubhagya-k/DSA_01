// Last updated: 05/08/2026, 16:54:00
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