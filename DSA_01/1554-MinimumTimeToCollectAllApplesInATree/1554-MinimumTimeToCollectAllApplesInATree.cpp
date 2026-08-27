// Last updated: 27/08/2026, 12:51:53
class Solution {
public:

int DFS(unordered_map<int,vector<int>>&adj,int current,int parent,vector<bool>& hasApple){

    int time = 0;

    for(int& child:adj[current]){
        if(child == parent){
            continue;
        }
        int time_require = DFS(adj,child,current,hasApple);

        if(time_require>0 || hasApple[child]){
            time += time_require+2;
        }
    }

    return time;

}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        unordered_map<int,vector<int>>adj;

        for(auto& vec:edges){

            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        return DFS(adj,0,-1,hasApple);
        
    }
};