class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& ds, int i){
        if(i == nums.size()){
            auto it = find(res.begin(), res.end(), ds);
            if(it == res.end()){
                res.push_back(ds);
            }
            return;
        }

        ds.push_back(nums[i]);
        solve(nums, res, ds, i + 1);
        ds.pop_back();
        solve(nums, res, ds, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>>res;
      vector<int>ds;
      sort(nums.begin(), nums.end());
      solve(nums, res, ds, 0);
      return res;
    }
};