// Last updated: 14/10/2026, 23:54:20
1#include <string>
2
3class Solution {
4public:
5    bool doesAliceWin(std::string s) {
6        // STEP 1: Count the total number of vowels in the string
7        int vowelCount = 0;
8        for (char c : s) {
9            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
10                vowelCount++;
11            }
12        }
13
14        // STEP 2: Check the exact conditions you mentioned
15
16        // Condition A: There are no vowels at all in the string
17        if (vowelCount == 0) {
18            return false; // Alice cannot make a move. Bob wins.
19        }
20        
21        // Condition B: The total count of vowels is an ODD number
22        else if (vowelCount % 2 != 0) {
23            // Alice can take the maximum number of items (the whole string)
24            // leaving 0 vowels for Bob. 
25            return true; // Alice wins automatically on turn 1.
26        }
27        
28        // Condition C: The total count of vowels is an EVEN number
29        else if (vowelCount % 2 == 0) {
30            // Alice will choose to pick a substring with an ODD number of vowels 
31            // (specifically, total vowels minus 1).
32            // This forces Bob into a losing trap where he can never clear the rest.
33            return true; // Alice wins by outsmarting Bob.
34        }
35
36        return false;
37    }
38};
39