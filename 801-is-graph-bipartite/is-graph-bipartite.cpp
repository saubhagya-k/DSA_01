class Solution {
public:

bool helperColored(vector<vector<int>>& graph,int curr,vector<int>&colored,int currColor){

    colored[curr] = currColor;

    for(int &br : graph[curr]){
        if(colored[br] == currColor){
            return false;
        }

        if(colored[br] == -1){
            int currcurrColor = 1 - currColor;

            if(helperColored(graph,br,colored,currcurrColor)==false){
                return false;
            }
        }
    }
    return true;

}
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int>colored(n,-1);


        for(int i=0;i<n;i++){

            if(colored[i]==-1){
            if(helperColored(graph,i,colored,1)==false){

                return false;

            }
        }
        }

        return true;

        
        
    }
};