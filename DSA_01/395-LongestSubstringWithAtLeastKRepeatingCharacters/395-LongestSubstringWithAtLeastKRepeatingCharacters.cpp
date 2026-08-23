// Last updated: 23/08/2026, 18:28:29
class Solution {
public:
    int longestSubstring(string s, int k) {


        int n = s.length();

        if(n==0 || n<k){
            return 0;
        }

        if(k<=1){
            return n;
        }

        unordered_map<char,int>map;

        for(char X :s){
            map[X]++;
        }

        int l = 0;

        while(l<n && map[s[l]]>=k){
            l++;
        }

        if(l>=n-1){
            return l;
        }

        int l1 = longestSubstring(s.substr(0,l),k);
        while(l<n && map[s[l]]<k){
            l++;
        }
      int l2 =(l<n)? longestSubstring(s.substr(l),k):0;


      return max(l1,l2);





        
    }
};