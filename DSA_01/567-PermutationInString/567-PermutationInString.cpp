// Last updated: 05/08/2026, 16:56:41
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> n1;
        unordered_map<char,int> n2;

        int leng = s1.length();
        int leng2 = s2.length();

       
        if (leng > leng2) return false;

        for(char a : s1){
            n1[a]++;
        }
        
        for(int i = 0; i < leng; i++){
            n2[s2[i]]++;
        }

        if(n1 == n2){
            return true;
        }

        for(int i = leng; i < leng2; i++){
             n2[s2[i]]++;

            
             char left = s2[i - leng]; 

             n2[left]--;

             if(n2[left] == 0){
                n2.erase(left);
             }

             if(n1 == n2){
                return true;
             }
        }

        return false;
    }
};
