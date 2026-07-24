class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {

        stack<int>st;

        long long total = 0;

        unordered_map<int,int>mp;

        for(int x:nums){
            while(!st.empty() && st.top()<x){
                mp.erase(st.top());
                st.pop();
               
            }

            st.push(x);
            mp[x]++;


            total += mp[x];

        }

        return total;

        
        
    }
};