// Last updated: 05/08/2026, 16:55:20
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        stack<int>st;

        vector<bool>visited(n,false);

        st.push(0);
        visited[0] = true;

        while(!st.empty()){
            int room = st.top();
            st.pop();

            for(int keys:rooms[room]){
                if(!visited[keys]){
                    visited[keys] = true;
                    st.push(keys);
                }
            }
        }

        for(bool v: visited){
            if (!v)return false;
        }

        return true;


        
    }
};