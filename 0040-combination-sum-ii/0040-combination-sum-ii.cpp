class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& ds) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            
            if (candidates[i] > target) break; 

            ds.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], res, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(), candidates.end()); 
        solve(0, candidates, target, res, ds);
        return res;
    }
};
