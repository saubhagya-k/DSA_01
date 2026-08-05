// Last updated: 05/08/2026, 16:52:19
class Solution {

    public:
    bool isVowel(char x){

        return x == 'a'||x=='e'||x=='i'||x=='o'||x=='u'||
        x == 'A'||x=='E'||x=='I'||x=='O'||x=='U';


    }
public:
    string sortVowels(string s) {

        string vowels = "";

        for(char x:s){
            if(isVowel(x)){
                vowels +=x;
            }
        }

        sort(vowels.begin(),vowels.end());

        int vowel_ptr = 0;

        for(int i=0;i<s.length();++i){
            if(isVowel(s[i])){
                s[i] = vowels[vowel_ptr];
                vowel_ptr++;
            }
            


        }
        return s;
        
    }
};