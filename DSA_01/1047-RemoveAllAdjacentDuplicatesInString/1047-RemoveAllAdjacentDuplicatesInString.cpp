// Last updated: 08/09/2026, 11:38:53
class Solution {
public:
    string removeDuplicates(string s) {

        stack<char>st;
        string mamu = "";

        for(char x :s){
            
            if(!st.empty() && st.top() == x){
                
              st.pop();
            }
            else{
                st.push(x);
            }
        }

        while(!st.empty()){
            mamu+=st.top();
            st.pop();
        }

        reverse(mamu.begin(),mamu.end());

      

       return mamu;
        
    }
};