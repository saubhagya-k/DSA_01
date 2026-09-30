// Last updated: 01/10/2026, 05:24:13
1#include <string>
2using namespace std;
3
4class Solution {
5public:
6    int romanToInt(string s) {
7        int result = 0;
8        char prev = ' '; // Tracks the previous character
9
10        for(char current : s) {
11
12            if (current == 'M') {
13                if (prev == 'C') result += 800;  // CM (900 total)
14                else result += 1000;
15            }
16            else if (current == 'D') {
17                if (prev == 'C') result += 300;  // CD (400 total)
18                else result += 500;
19            }
20            else if (current == 'C') {
21                if (prev == 'X') result += 80;  
22                else result += 100;
23            }
24            else if (current == 'L') {
25                if (prev == 'X') result += 30;   // XL (40 total)
26                else result += 50;
27            }
28            else if (current == 'X') {
29                if (prev == 'I') result += 8;    // IX (9 total)
30                else result += 10;
31            }
32            else if (current == 'V') {
33                if (prev == 'I') result += 3;    // IV (4 total)
34                else result += 5;
35            }
36            else if (current == 'I') {
37                result += 1;
38            }
39
40            prev = current; // Save current character for the next loop
41        }
42        
43        return result;
44    }
45};
46