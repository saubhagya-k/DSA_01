// Last updated: 05/08/2026, 16:53:41
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        unordered_map<int,vector<pair<int,double>>>adj;

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        

        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;

        vector<double>result(n,0.0);

        result[start_node] = 1.0;

        pq.push({1.0,start_node});


        while(!pq.empty()){
            double d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end_node) return d;


            for(auto &ver : adj[node]){

                int adjNode = ver.first;
                double dist = ver.second;

                if(d*dist>result[adjNode]){
                    result[adjNode] = d*dist;

                    pq.push({result[adjNode],adjNode});
                }

            }
        }

        return 0.0;


    }
};