// Last updated: 05/08/2026, 16:57:33
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0;
        int max_freq = 0;
        int max_length = 0;
        unordered_map<char, int> counts;

        for (int right = 0; right < n; right++) {
            
            counts[s[right]]++;
            
          
            max_freq = max(max_freq, counts[s[right]]);

            
            while ((right - left + 1) - max_freq > k) {
                counts[s[left]]--;
                left++;
            }

           
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
