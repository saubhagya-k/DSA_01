// Last updated: 05/08/2026, 17:03:26
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        unordered_map<char,int>good;

        int left = 0;
        int max_count = 0;

        

        for(int right = 0;right<n;right++){
           good[s[right]]++;

           while(good[s[right]]>1){
            good[s[left]]--;

            if(good[s[left]] == 0){
                good.erase(s[left]);
            }
            left++;
           }

            max_count = max(max_count,right-left+1);

        }
       
        return max_count;
        
    }
};