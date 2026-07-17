class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if(ransomNote.length()>magazine.length()){
            return false;
        }

        vector<int>ans(26,0);

        for(char X: magazine){
            ans[X - 'a']++;

        }

        for(char X: ransomNote){
            ans[X - 'a']--;

            if(ans[X - 'a'] <0){
                return false;
            }
        }

        return true;



      
        
    }
};