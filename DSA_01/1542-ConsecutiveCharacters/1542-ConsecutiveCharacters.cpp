// Last updated: 23/08/2026, 18:26:07
class Solution {
public:
    int maxPower(string s) {

        int n = s.length();
        int curr = 0;

        int prev = s[0];

        int maxfre = 0;

        int count = 1;

        if(n==1){
            return 1;
        }

        // we will sue here two pointers

        for(int i = 1;i<n;i++){
            curr = s[i];

            if(curr == prev){

                count++;
                
            }
            
        if(curr!=prev){
            count = 1;
         }

          prev = curr;

         maxfre = max(maxfre,count);



        }

        return maxfre;
        
    }
};