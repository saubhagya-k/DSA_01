// Last updated: 27/09/2026, 00:46:28
// if the bound id more than 1 , eg is 2,3,4... the it will be very easy to swap between any two elements , and in any where , but when in less thn on is though
1class Solution {
2public:
3    string orderlyQueue(string s, int k) {
4
5        if(k>1){
6            sort(s.begin(),s.end());
7        }
8
9        int n = s.length();
10
11        string result = s ;
12
13        for(int l=1;l<n;l++){
14            string temp = s.substr(l)+s.substr(0,l);
15
16            result = min(result,temp);
17        }
18
19        return result;
20        
21    }
22};