// Last updated: 05/08/2026, 16:51:46
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper to calculate permutations of the remaining multiset, capped at limit+1
    long long countPermutations(const vector<int>& count, long long limit) {
        int distinct_chars = 0;
        for (int c : count) {
            if (c > 0) distinct_chars++;
        }
        // If 0 or 1 unique character types are left, there is only 1 unique way to arrange them
        if (distinct_chars <= 1) return 1;

        long long ans = 1;
        int n_elements = 0;
        for (int c : count) {
            if (c == 0) continue;
            for (int i = 1; i <= c; i++) {
                n_elements++;
                ans = ans * n_elements / i;
                if (ans > limit) return limit + 1; // Prevent overflow
            }
        }
        return ans;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string mid = "";
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                mid = (char)('a' + i);
            }
            count[i] /= 2; // Keep only the characters needed for the first half
        }
        
        // Check if k exceeds the total possible distinct palindromic permutations
        long long total_ways = countPermutations(count, k);
        if (total_ways < k) return "";
        
        string halfResult = "";
        int half = n / 2;
        
        // Construct the first half lexicographically
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < 26; j++) {
                if (count[j] > 0) {
                    count[j]--; // Tentatively place character j
                    long long ways = countPermutations(count, k);
                    
                    if (k <= ways) {
                        halfResult += (char)('a' + j);
                        break; // Character j is fixed for position i
                    } else {
                        k -= ways;
                        count[j]++; // Backtrack and try next character
                    }
                }
            }
        }
        
        // Reconstruct the full palindrome using the first half and middle character
        string rev = halfResult;
        reverse(rev.begin(), rev.end());
        return halfResult + mid + rev;
    }
};
