// Last updated: 05/08/2026, 16:58:58
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> ans;
        vector<int> InDeg(numCourses, 0);

        
        for(int i = 0; i < prerequisites.size(); i++){
            InDeg[ prerequisites[i][0] ]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(!InDeg[i])
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            
            for(int i = 0; i < prerequisites.size(); i++){
                if(prerequisites[i][1] == node){
                    InDeg[ prerequisites[i][0] ]--;
                    if(InDeg[ prerequisites[i][0] ] == 0)
                        q.push(prerequisites[i][0]);
                }
            }
        }

       
        if(ans.size() != numCourses)
            return {};

        return ans;
    }
};
