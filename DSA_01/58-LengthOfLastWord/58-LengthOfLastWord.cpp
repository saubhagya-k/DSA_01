// Last updated: 05/08/2026, 17:02:29
class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.length();

        int count = 0;


        reverse(s.begin(),s.end());

        for(int i=0;i<n;i++){
           

            if (s[i] != ' ') {
                count++; 
            } 
            else {
                
                if (count > 0) {
                    break;
                }
            }

        }

        return count;
        

    }
};