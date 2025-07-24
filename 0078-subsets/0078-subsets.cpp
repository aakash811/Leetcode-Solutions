class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds, vector<vector<int>>& res, int idx){
        if(idx == nums.size()){
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        solve(nums, ds, res, idx + 1);
        ds.pop_back();
        solve(nums, ds, res, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;

        solve(nums, ds, res, 0);
        return res;
    }
};