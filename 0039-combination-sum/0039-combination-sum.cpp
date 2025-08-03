class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& ds, vector<int>& vec, int target, int idx){
        if(idx == vec.size()){
            if(target == 0){
                res.push_back(ds);
            }
            return;
        }

        if(target >= vec[idx]){
            ds.push_back(vec[idx]);
            solve(res, ds, vec, target - vec[idx], idx);
            ds.pop_back();
        }
        solve(res, ds, vec, target, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& vec, int target) {
        vector<vector<int>>res;
        vector<int>ds;

        solve(res, ds, vec, target, 0);
        return res;
    }
};