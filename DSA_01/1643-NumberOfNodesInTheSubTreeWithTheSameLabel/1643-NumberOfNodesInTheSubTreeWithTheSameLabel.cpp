// Last updated: 30/08/2026, 12:34:12
class Solution {
public:

vector<int>dfs(unordered_map<int,vector<int>>&adj, int curr,int parent,vector<int>&result,string&labels){

    vector<int>myCount(26,0);

    char mylabel = labels[curr];
    myCount[mylabel-'a'] = 1;

    for(int &v : adj[curr]){
        if(v==parent) continue;


        vector<int>child_count(26,0);

        child_count = dfs(adj,v,curr,result,labels);

        for(int i=0;i<26;i++){
            myCount[i] += child_count[i];
        }

        
    }
    result[curr] = myCount[mylabel-'a'];

        return myCount;



}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        unordered_map<int,vector<int>>adj;

        for(auto &vec :edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>result(n,0);

        dfs(adj,0,-1,result,labels);

        return result;


        
        
    }
};