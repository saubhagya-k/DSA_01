// Last updated: 05/08/2026, 16:59:10
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;

        }

        vector<int>ms(256,0);
        vector<int>mt(256,0);


        for(int i=0;i<s.length();i++){
            if(ms[s[i]] != mt[t[i]]){
                return false;
            }

            ms[s[i]] = i+1;
            mt[t[i]] = i+1;



        }
        return true;



        
    }
};