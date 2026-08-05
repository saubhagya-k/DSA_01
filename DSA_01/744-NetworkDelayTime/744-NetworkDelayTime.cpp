// Last updated: 05/08/2026, 16:55:53
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int ,vector<pair<int,int>>>adj;
        for(const auto &edge: times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>result(n+1,INT_MAX);

        result[k] = 0;

        pq.push({0,k});

        while(!pq.empty()){
           int d = pq.top().first;
           int node = pq.top().second;

            pq.pop();

            for(auto &vec :adj[node]){
                int adjNode = vec.first;
                int dist = vec.second;


                if(d+dist<result[adjNode]){
                    result[adjNode] = d+dist;

                    pq.push({d+dist,adjNode});
                }

            }
        }

        int maxDelay = 0;

        for(int i=1;i<=n;i++){

            if(result[i] == INT_MAX){
                return -1;
            }
            maxDelay = max(maxDelay,result[i]);

        }

        return maxDelay;




       
        
    }
};