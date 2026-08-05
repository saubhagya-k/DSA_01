// Last updated: 05/08/2026, 16:57:26
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n1 = s.length();
        int n2 = p.length();

        vector<int>result;

        if (n1 < n2) return result;

        unordered_map<char,int>map1;
        unordered_map<char,int>map2;

        for(char x:p){
            map2[x]++;
        }

        for(int i=0;i<n2;i++){
            map1[s[i]]++;

            
        }

        if(map2 == map1){

            result.push_back(0);

        }

        for(int i=n2;i<n1;i++){
            map1[s[i]]++;

            char left = s[i-n2];
            
            map1[left]--;

            if(map1[left] == 0){
                map1.erase(left);
            }

            if(map1 == map2){
                result.push_back(i-n2+1);
            }
        }


        return result;




        
    }
};