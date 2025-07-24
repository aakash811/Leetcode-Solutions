class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& res, int idx){
        if(target == 0){
            res.push_back(ds);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i - 1]){
                continue;
            }

            if(candidates[i] > target){
                break;
            }         

            ds.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ds, res, i + 1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ds;
        
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ds, res, 0);
        return res;
    }
};