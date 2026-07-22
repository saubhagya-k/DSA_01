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