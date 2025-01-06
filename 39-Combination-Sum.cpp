class Solution {
public:

    void solve(int ind, int target,vector<int>candidates, vector<int>& ds, vector<vector<int>>& res)
    {
        if(ind == candidates.size())
        {
            if(target == 0)
            {
                res.push_back(ds);
            }
            return;
        }

        if(candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            solve(ind, target-candidates[ind], candidates, ds, res);
            ds.pop_back();
        }
        solve(ind + 1, target, candidates, ds, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> ds;
        solve(0, target, candidates, ds, res);
        return res;
    }
};