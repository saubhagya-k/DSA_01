class Solution {
    bool dfs(unordered_map<int,vector<int>>&graph,int source, int destination,vector<bool>&vis,int n){

        if(source == destination){
            return true;
        }

        vis[source] = true;

        for(auto neighbor:graph[source]){
            if(!vis[neighbor]){
               if( dfs(graph,neighbor,destination,vis,n)){
                return true;
               }
            }
        }
        return false;

    }



public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        unordered_map<int,vector<int>>graph;

        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);

        }

        vector<bool>vis(n,false);
        return dfs(graph,source,destination,vis,n);
        
    }
};