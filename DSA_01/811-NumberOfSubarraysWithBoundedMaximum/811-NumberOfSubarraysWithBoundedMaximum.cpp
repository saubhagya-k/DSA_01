// Last updated: 05/08/2026, 16:55:32
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        int rwindow = 0;
        int lwindow = 0;


        int rtotal = 0;
        int ltotal = 0;

        for(int x : nums){
            if(x>right){
                rwindow = 0;
            }
            else{
                rwindow++;
            }

            rtotal+=rwindow;
        }

        for(int x:nums){
            if(x>left-1){
                lwindow = 0;



                
            }
            else{
                lwindow++;
            }
            ltotal +=lwindow;
        }

        return rtotal-ltotal;
        
    }
};