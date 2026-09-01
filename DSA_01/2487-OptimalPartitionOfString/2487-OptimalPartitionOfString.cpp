// Last updated: 01/09/2026, 16:19:09
class Solution {
public:
    int partitionString(string s) {
        // Changed to char to match the string's characters properly
        vector<char> temp;
        vector<vector<char>> final;

        for (char X : s) {
            
            if (std::find(temp.begin(), temp.end(), X) != temp.end()) {
               
                final.push_back(temp);
                temp.clear();
            }
            
           
            temp.push_back(X);
        }

       
        if (!temp.empty()) {
            final.push_back(temp);
        }

        return final.size();
    }
};
