// Last updated: 23/08/2026, 18:27:19
class Solution {
public:
    int repeatedStringMatch(string a, string b) {

       
        int count = 1;

        string original_a = a;

        while(a.length()<b.length()){
            a+=original_a;
            count++;
        }

        if(a.find(b) != string::npos){
            return count;
        }

        a+=original_a;

        if(a.find(b)!= string::npos){
            return count+1;
        }

        return -1;
        
    }
};