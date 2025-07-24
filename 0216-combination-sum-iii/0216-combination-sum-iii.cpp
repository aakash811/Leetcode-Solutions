class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& ds, int k, int n, int idx){
        if(idx == 10){
            if(k == 0){
                if(n == 0){
                    res.push_back(ds);
                }
            }
            return;
        }

        if(idx <= n){
            ds.push_back(idx);
            solve(res, ds, k - 1, n - idx, idx + 1);
            ds.pop_back();
        }
        solve(res, ds, k, n, idx + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>ds;

        solve(res, ds, k, n, 1);
        return res;
    }
};