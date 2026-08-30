// Last updated: 30/08/2026, 12:33:09
class Solution {
public:
char midChar = '$';
int halfLen = 0;

string result = "";

bool solve(string &curr,vector<int>&count,string &target,int i,int greater){

    if(curr.length() == halfLen){
        string candidate = curr;
        string right = curr;

        reverse(begin(right),end(right));

        if(midChar != '$'){
            candidate += midChar;
        }

        candidate+=right;

        if(candidate>target){
            result = candidate;
            return true;
        }

        return false;
    }

    for(char ch = 'a' ;ch<='z';ch++){
        if(count[ch-'a']==0)  continue;

        if(!greater && ch <target[i]){
            continue;
        }

        curr.push_back(ch);
        count[ch-'a']--;

        bool isGreater = greater || ch>target[i];

        if(solve(curr,count,target,i+1,isGreater)){
            return true;
        }

        curr.pop_back();
        count[ch-'a']++;
    }

    return false;
}


    string lexPalindromicPermutation(string s, string target) {

        int n = s.length();

        int odd_count = 0;

        vector<int>count(26,0);

        for(char X : s){
            count[X-'a']++;
        }

        for(int i=0;i<26;i++){
            if(count[i]%2 == 1){
                odd_count++;

                midChar = i+'a';
            }
        }

        if(odd_count>1){
            return "";
        }

        for(int i=0;i<26;i++){
            count[i]/=2;
        }

        halfLen = n/2;

        string curr = "";

        solve(curr,count,target,0,false);

        return result;
        
    }
};