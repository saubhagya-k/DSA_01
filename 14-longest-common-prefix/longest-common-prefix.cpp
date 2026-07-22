class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());

        int n = strs.size();

        string a = strs[0];
        string b = strs[n-1];

        int m = a.length();

        string same = "";


        for(int i=0;i<m;i++){
            if(a[i] == b[i]){

                same+=a[i];

            }
            else{
                break;
            }

        }

        return same;
        
    }
};