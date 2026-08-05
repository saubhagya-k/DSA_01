// Last updated: 05/08/2026, 16:52:05
#include <string>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        int n = word.length();
        int totalPushes = 0;
        
       
        for (int i = 0; i < n; ++i) {
            
            totalPushes += (i / 8) + 1;
        }
        
        return totalPushes;
    }
};
