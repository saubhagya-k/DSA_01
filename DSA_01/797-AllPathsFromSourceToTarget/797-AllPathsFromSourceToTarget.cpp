// Last updated: 08/09/2026, 13:36:10
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