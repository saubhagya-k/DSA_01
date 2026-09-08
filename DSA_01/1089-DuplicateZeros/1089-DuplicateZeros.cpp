// Last updated: 08/09/2026, 11:38:36
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int size = arr.size();

        vector<int>results;

        for(int i=0;i<size;i++){
            if(arr[i]==0){
                results.push_back(0);
                
                if(results.size()<size){
                    results.push_back(0);
                }

            }
            else{
                results.push_back(arr[i]);
            }

            if(results.size()>=size){
                break;
            }
        }

        arr = results;
        
    }
};