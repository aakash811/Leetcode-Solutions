class Solution {
public:
    map<pair<int,int>,int>dp;
    int solve(int idx, int sum, vector<int>& nums, int target){
        int n = nums.size();
        if(sum == target && idx == n){
            return 1;
        }
        if(idx >= n){
            return 0;
        }
        if(dp.find({idx,sum}) != dp.end()){
            return dp[{idx,sum}];
        }
        int add = solve(idx + 1, sum + nums[idx], nums, target);
        int sub = solve(idx + 1, sum - nums[idx], nums, target);
        return dp[{idx,sum}] = add + sub;
    }
    int findTargetSumWays(vector<int>&nums,int target) {
        return solve(0,0,nums,target);
    }
};