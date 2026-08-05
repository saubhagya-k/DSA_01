// Last updated: 05/08/2026, 16:59:13
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; 

        
        vector<bool> isPrime(n, true);
        int count = 0;

        
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++; 
                
              
                for (long long j = (long long)i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        return count;
    }
};
