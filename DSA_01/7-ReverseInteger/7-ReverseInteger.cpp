// Last updated: 05/08/2026, 17:03:23
class Solution {
public:
    int reverse(int x) {
        int reverse = 0;

        while (x != 0) {
            int n = x % 10;

            // Check for overflow before doing reverse * 10
            if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
                return 0;

            reverse = reverse * 10 + n;
            x = x / 10;
        }

        return reverse;
    }
};
