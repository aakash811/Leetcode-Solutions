class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, int idx){
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }

        unordered_set<int>used;
        for(int j = idx; j < nums.size(); j++){
            if(used.count(nums[j])){
                continue;
            }
            
            used.insert(nums[j]);
            
            swap(nums[idx], nums[j]);
            solve(nums, res, idx + 1);
            swap(nums[idx], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        solve(nums, res, 0);
        return res;
    }
};