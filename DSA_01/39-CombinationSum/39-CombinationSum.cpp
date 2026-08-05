// Last updated: 05/08/2026, 17:02:44
class Solution {
public:

    void ans(vector<int>& candidates, int target, int start,
             vector<int>& path, vector<vector<int>>& final) {

        if (target == 0) {
            final.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            if (candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);

            ans(candidates, target - candidates[i], i, path, final);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> final;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        ans(candidates, target, 0, path, final);

        return final;   // ❗ IMPORTANT (you missed this)
    }
};