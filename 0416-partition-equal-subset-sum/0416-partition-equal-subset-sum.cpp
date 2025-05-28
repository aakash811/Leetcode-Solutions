class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int half = sum / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;

        for (int it : nums) {
            for (int j = half; j >= it; --j) {
                dp[j] = dp[j] || dp[j - it];
                if(dp[half]){
                    return true;
                }
            }
        }
        return false;
    }
};