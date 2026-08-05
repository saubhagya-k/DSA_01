// Last updated: 05/08/2026, 16:52:02
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        
        std::vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        
        std::sort(freq.rbegin(), freq.rend());
        
        
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) break; 
            
           
            totalPushes += freq[i] * ((i / 8) + 1);
        }
        
        return totalPushes;
    }
};
