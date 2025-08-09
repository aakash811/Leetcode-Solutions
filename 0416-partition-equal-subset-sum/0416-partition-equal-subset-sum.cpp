class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }

        int req = sum / 2;
        vector<int>dp(req + 1, false);
        dp[0] = true;

        for(int i = 0; i < nums.size(); i++){
            for(int j = req; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[req];
    }
};