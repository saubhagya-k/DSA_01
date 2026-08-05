// Last updated: 05/08/2026, 16:52:20
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