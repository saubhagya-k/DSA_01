// Last updated: 03/09/2026, 05:10:11
1class Solution {
2public:
3    string breakPalindrome(string palindrome) {
4        int n = palindrome.size();
5
6        if(n == 1){
7            return "";
8        }
9
10        for(int i=0;i<n/2;i++){
11            if(palindrome[i] !='a'){
12                palindrome[i] = 'a';
13                return palindrome;
14            }
15        }
16
17        palindrome[n-1] = 'b';
18
19        return palindrome;
20        
21    }
22};