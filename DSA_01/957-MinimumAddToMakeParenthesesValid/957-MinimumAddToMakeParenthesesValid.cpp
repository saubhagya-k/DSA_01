// Last updated: 23/08/2026, 18:26:56
class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char>st;

        int n = s.length();

        if(n==0){
            return 0;
        }

        st.push(s[0]);

        int i=1;

       while(i<n){
       
        if(!st.empty() && st.top() =='(' && s[i] == ')'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
        i++;
       }

       return st.size();
    }
};