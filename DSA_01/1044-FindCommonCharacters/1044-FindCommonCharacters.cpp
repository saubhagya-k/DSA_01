// Last updated: 05/08/2026, 16:54:33
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        unordered_map<char,int> leja;

        vector<string> deja;

        
        for(char c : words[0]) {
            leja[c]++;
        }

        
        for(int i = 1; i < words.size(); i++) {

            unordered_map<char,int> temp;

           
            for(char c : words[i]) {
                temp[c]++;
            }

            
            for(auto &it : leja) {

                it.second = min(it.second, temp[it.first]);
            }
        }

        
        for(auto &it : leja) {

            while(it.second > 0) {

                string s(1, it.first);

                deja.push_back(s);

                it.second--;
            }
        }

        return deja;
    }
};