class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum - target < 0 || (sum - target) % 2 != 0){
            return false;
        }

        int s1 = (sum - target) / 2;     

        vector<int>dp(s1 + 1, 0);
        if(nums[0] == 0){
            dp[0] = 2;
        }
        else{
            dp[0] = 1;

            if(nums[0] <= s1){
                dp[nums[0]] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            vector<int>prev(s1 + 1, 0);
            for(int j = 0; j <= s1; j++){
                int notTake = dp[j];
                int take = 0;
                if(nums[i] <= j){
                    take = dp[j - nums[i]];
                }
                prev[j] = take + notTake;
            }
            dp = prev;
        }                                 
        return dp[s1];     
    }
};