// Last updated: 05/08/2026, 16:57:19
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.length();

       

        for(int i=1;i<=n/2;i++){

            if(n%i==0){
               int times = n/i;

               string pattern = s.substr(0,i);

               string newString = "";

               while(times--){
                newString += pattern;
               }
               if(newString == s){
                return true;
               }
            }

        }
        return false;
        
    }
};