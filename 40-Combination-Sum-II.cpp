class Solution {
public:
    void solve(int ind, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& st)
    {
        if(target == 0)
        {
            st.push_back(ds);
            return;
        }

        for(int i = ind; i < arr.size(); i++)
        {
            if(i > ind && arr[i] == arr[i - 1]) continue;

            if(arr[i] > target) break;

            ds.push_back(arr[i]);
            solve(i + 1, target - arr[i], arr, ds, st);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>>st;
        vector<int>ds;

        solve(0, target, arr, ds, st);

        return st;
    }
};