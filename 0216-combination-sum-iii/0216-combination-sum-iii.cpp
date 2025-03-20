class Solution {
public:
    void solve(int k, int n, vector<vector<int>>& res, vector<int>& ds, int i){
        if(i == 10){
            if(k == 0){
                if(n == 0)
                {
                    res.push_back(ds);
                }
            }
            return;
        }

        if(i <= n){
            ds.push_back(i);
            solve(k - 1, n - i, res, ds, i + 1);
            ds.pop_back();
        }
        solve(k, n, res, ds, i + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>ds;
        solve(k, n, res, ds, 1);
        return res;
    }
};