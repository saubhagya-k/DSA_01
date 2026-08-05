// Last updated: 05/08/2026, 16:58:09
class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<bool>after(26,false);

        vector<int>taken(26);

        string result = "";

       int n = s.length();

       for(int i=0;i<n;i++){
        char c = s[i];

        taken[c-'a'] = i;
       }

       for(int i = 0;i<n;i++){

        char ch = s[i];
        int idx = ch - 'a';


        if(after[idx] == true){
            continue;
        }

        while(result.length()>0 && result.back()>ch && taken[result.back()-'a']>i){
            after[result.back()-'a'] = false;

            result.pop_back();
        }

        result.push_back(ch);

        after[idx] = true;


       }

       return result;
        
    }
};