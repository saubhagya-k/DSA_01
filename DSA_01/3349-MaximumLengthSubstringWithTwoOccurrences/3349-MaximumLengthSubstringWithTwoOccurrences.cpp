// Last updated: 23/08/2026, 18:25:08
class Solution {
public:
    int maximumLengthSubstring(string s) {

        int n = s.length();

        int start = 0;

        int mls = INT_MIN;

        int end = 0;

        if(n == 0) return 0;

        int arr[26] = {0};

       int j = 0;

       for(int i=0;i<n;i++){
        arr[s[i]-'a']++;

        while(arr[s[i]-'a']>2){
            arr[s[j]-'a']--;
            j++;
        }
        mls = max(mls,i-j+1);
       }

       return mls;


       
       

        
    }
};