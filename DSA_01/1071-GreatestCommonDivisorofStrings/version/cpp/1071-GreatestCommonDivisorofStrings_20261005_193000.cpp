// Last updated: 05/10/2026, 19:30:00
1class Solution {
2public:
3    string gcdOfStrings(string str1, string str2) {
4
5        if(str1+str2!=str2+str1){
6            return "";
7        }
8        
9        int gcd_length = gcd(str1.length(),str2.length());
10
11        return str2.substr(0,gcd_length);
12    }
13};