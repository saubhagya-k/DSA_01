// Last updated: 27/08/2026, 12:51:06
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.length();

        int left = 0;
        int right = 0;

        int count_one = 0;

        int min_length = n+1;

        string ans = "";

        while(right<n){
            if(s[right] == '1'){
                count_one++;
            }

            while(count_one == k){
                int len = right-left+1;
                string ok = s.substr(left,len);

                if(len<min_length){
                    min_length = len;

                    ans = ok;
                    }

                    else if(len == min_length){
                        if(ans== "" || ok<ans){
                            ans = ok;
                        }
                    }

                    if(s[left]=='1'){
                        count_one--;
                    }

                    left++;
            
            }
            right++;
        }

        return ans;

    }
};