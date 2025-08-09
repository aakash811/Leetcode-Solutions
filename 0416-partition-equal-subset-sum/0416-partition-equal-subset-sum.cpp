class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        int target = sum / 2;

        vector<int>dp(target + 1, false);
        dp[0] = true;

        if(nums[0] <= target){
            dp[nums[0]] = true;
        }
        
        for(int i = 1; i < nums.size(); i++){
            vector<int>prev(target + 1, false);
            prev[0] = true;
            for(int j = 1; j <= target; j++){
                bool notTaken = dp[j];
                bool taken = false;
                if(nums[i] <= j){
                    taken = dp[j - nums[i]];
                }
                prev[j] = notTaken || taken;
            }
            dp = prev;
        }

        return dp[target];
    }
};