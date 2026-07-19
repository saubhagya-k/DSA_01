class Solution {
public:

void helper(unordered_map<int,vector<int>>&adj, vector<bool>&visited,int u){

    visited[u] = true;

    for(int &v:adj[u]){
        if(!visited[v]){
            helper(adj,visited,v);
        }

    }

}
    int findCircleNum(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

        int count = 0;

        vector<bool>visited(n,false);

        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                helper(adj,visited,i);

                count++;

            }
        }

        return count;
        
    }
};