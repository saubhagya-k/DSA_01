// Last updated: 05/08/2026, 17:02:51
class Solution {
public:
    int strStr(string haystack, string needle) {

        int pos = 0;

        pos = haystack.find(needle);

        if(pos == string::npos){
            return -1;
        }

        return pos;
        
    }
};