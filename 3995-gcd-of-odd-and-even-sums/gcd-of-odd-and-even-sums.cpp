#include <numeric> // Required for std::gcd

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 0;
        long long sumEven = 0;

        // The first n odd and even numbers fall within the range 1 to 2*n
        for (int i = 1; i <= 2 * n; i++) {
            if (i % 2 == 0) {
                sumEven += i;
            } else {
                sumOdd += i;
            }
        }

        // Compute GCD using modern standard library features
        return std::gcd(sumOdd, sumEven);
    }
};
