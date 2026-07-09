class Solution {
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

        vis[source] = true;

        queue<int>q;
        q.push(source);

        while(!q.empty()){
            int curr = q.front();

            q.pop();

            if(curr == destination) return true;

            for(int neighbor:graph[curr]){
                if(!vis[neighbor]){
                    q.push(neighbor);

                    vis[neighbor] = true;
                }
            }





        }


        return false;
        
    }
};