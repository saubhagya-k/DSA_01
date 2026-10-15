// Last updated: 15/10/2026, 23:22:24
1class Solution {
2public:
3    // Helper function to check if a segment is a valid IP number
4    bool isValid(string segment) {
5        if (segment.empty() || segment.length() > 3) return false;
6        
7        // Check for leading zeros (allowed only if the segment is exactly "0")
8        if (segment.length() > 1 && segment[0] == '0') return false;
9        
10        // Check if the value is within the 0-255 range
11        int num = stoi(segment);
12        return num >= 0 && num <= 255;
13    }
14
15    vector<string> restoreIpAddresses(string s) {
16        vector<string> result;
17        int n = s.length();
18        
19        // An IP string with dots will be at most 12 chars and at least 4 chars
20        if (n < 4 || n > 12) return result;
21
22        // i, j, k represent the lengths of the first three segments
23        for (int i = 1; i <= 3 && i < n; i++) {
24            for (int j = 1; j <= 3 && i + j < n; j++) {
25                for (int k = 1; k <= 3 && i + j + k < n; k++) {
26                    
27                    // Split the string into 4 components based on the lengths
28                    string s1 = s.substr(0, i);
29                    string s2 = s.substr(i, j);
30                    string s3 = s.substr(i + j, k);
31                    string s4 = s.substr(i + j + k); // Takes the remaining characters
32
33                    // If all 4 segments are valid, we found a match!
34                    if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
35                        result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
36                    }
37                }
38            }
39        }
40        return result;
41    }
42};
43