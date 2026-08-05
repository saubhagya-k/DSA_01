// Last updated: 05/08/2026, 16:53:29
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {


        unordered_set<int>s;

        for(int i=0;i<arr.size();i++){
            if(s.count(arr[i]*2) || s.count(arr[i]/2) && arr[i] % 2==0){
                return true;
            }
            s.insert(arr[i]);
        }
        return false;


        
    }
};