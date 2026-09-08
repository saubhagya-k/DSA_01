// Last updated: 08/09/2026, 11:33:14
class Solution {
public:
    int minimizedStringLength(string s) {


        std::vector<bool> seen(26, false);
        int unique_count = 0;
        
        for (char c : s) {
            
            if (!seen[c - 'a']) {
                seen[c - 'a'] = true;
                unique_count++;
            }
        }
        
        return unique_count;
        


    }
    
};