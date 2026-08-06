// Last updated: 07/08/2026, 00:23:27
class Solution {
public:
void dfs(vector<vector<int>>& stones,int index, vector<int>&visited){
    visited[index] = 1;

    for(int i=0;i<stones.size();i++){

        if(visited[i] == 0 && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])){
            dfs(stones,i,visited);
        }

    }
}
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        int group = 0;

        vector<int>visited(n,0);

        for(int i=0;i<n;i++){

            if(visited[i] == 1){
                continue;
            }
            dfs(stones,i,visited);
            group++;
        }

        return (n-group);
        
    }
};