// Last updated: 08/09/2026, 11:33:46
class Solution {
public:
    string removeStars(string s) {

        int n = s.length();

        int j = 0;

        for(int i=0;i<n;i++){

            if(s[i]=='*'){

                if(j>0){
                    j--;
                }
            }
            else{
                s[j] = s[i];
                j++;
            }

            

        }

        s.resize(j);

        return s;
        
    }
};