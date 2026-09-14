// Last updated: 14/09/2026, 23:48:27
1#include <vector>
2
3class Solution {
4public:
5    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
6        // Check if either rectangle is actually a line
7        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || 
8            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
9            // The line cannot have positive overlap
10            return false;
11        }
12        
13        return !(rec1[2] <= rec2[0] || // left
14                 rec1[3] <= rec2[1] || // bottom
15                 rec1[0] >= rec2[2] || // right
16                 rec1[1] >= rec2[3]);  // top
17    }
18};
19