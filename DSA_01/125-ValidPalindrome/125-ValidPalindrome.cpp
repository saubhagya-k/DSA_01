// Last updated: 05/08/2026, 17:00:47
class Solution {
public:
void helper(string&s){

    string dad = "";

    for(char x:s){
        if(isalnum(x)){          // isalnum checks if the character is a letter or a number
            dad+=tolower(x);
        }
        
        }
        s = dad;

}
    bool isPalindrome(string s) {

        stack<char>db;

        string momo = "";

        helper(s);




        

        int n = s.length();

        for(char x:s){
            db.push(x);
        }

        for(int i=0;i<n;i++){

            momo += db.top();

            db.pop();
        }

        if(momo == s){
            return true;
        }
        else{
            return false;
        }





    


        
    }
};