// Last updated: 05/08/2026, 16:55:55
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
      
        vector<int> result(n, 0); 
        stack<int> st; 

        for(int i = 0; i < n; i++) {
            
            
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int popped_index = st.top();
                st.pop();
                
                
                result[popped_index] = i - popped_index;
            }
            
            
            st.push(i);
        }
        
        return result;
    }
};
