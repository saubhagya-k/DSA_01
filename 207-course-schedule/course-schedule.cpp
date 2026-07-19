class Solution {
public:


bool isCycledfs( vector<vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&inRecursion){

    visited[u] = true;
    inRecursion[u] = true;

    for(int &v : adj[u]){

        if(visited[v] == false && isCycledfs(adj,v,visited,inRecursion)){

            return true;

        }

        else if(inRecursion[v] == true){
            return true;
        }

    }

    inRecursion[u] = false;

    return false;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        for(auto x :prerequisites){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
        }

        vector<bool>visited(numCourses,false);
        vector<bool>inRecursion(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && isCycledfs(adj,i,visited,inRecursion))

            return false;
        }

        return true;
        
    }
};