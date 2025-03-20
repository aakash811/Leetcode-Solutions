class Solution {
public:
    vector<vector<int>>subset;
    void solve(vector<int>& nums, vector<int>& subs, int i){
        if(i == nums.size()){
            subset.push_back(subs);
            return;
        }

        subs.push_back(nums[i]);
        solve(nums, subs, i + 1);
        subs.pop_back();
        solve(nums, subs, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subs;
        solve(nums, subs, 0);
        return subset;
    }
};