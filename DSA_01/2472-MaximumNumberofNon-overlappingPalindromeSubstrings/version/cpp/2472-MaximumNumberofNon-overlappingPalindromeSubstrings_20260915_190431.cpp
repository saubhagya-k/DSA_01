// Last updated: 15/09/2026, 19:04:31
1class Solution {
2public:
3bool isPalindrome(string& s,int left,int right){
4
5    while(left<right){
6        if(s[left] != s[right] ) return false;
7        left++;
8        right--;
9    }
10    return true;
11
12}
13int countPalindromeRecursion(string& s, int k , int start){
14
15    int n = s.length();
16
17    if(start>n-k){
18        return 0;
19    }
20
21    if(isPalindrome(s,start,start+k-1)){
22        return 1+countPalindromeRecursion(s,k,start+k);
23    }
24
25    if(start+k<n && isPalindrome(s,start,start+k)){
26        return 1+countPalindromeRecursion(s,k,start+k+1);
27    }
28
29    return countPalindromeRecursion(s,k,start+1);
30
31}
32    int maxPalindromes(string s, int k) {
33
34        int n = s.length();
35
36        int start = 0;
37
38       return countPalindromeRecursion(s,k,start);
39
40        
41    }
42};