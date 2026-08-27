// Last updated: 27/08/2026, 12:53:13
class Solution {
public:

void dfs(vector<vector<int>>& graph, vector<vector<int>>& result,vector<int>& temp,int u,int target){

    temp.push_back(u);

    if(u == target){
        result.push_back(temp);
    }

   else{
    for(int &v:graph[u]){
        dfs(graph,result,temp,v,target);
    }
   }
   temp.pop_back();
}


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();

        int source = 0;
        int target = n-1;

        vector<vector<int>>result;
        vector<int>temp;

        dfs(graph,result,temp,source,target);

        return result;
        
    }
};