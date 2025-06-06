class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 0; i <= amount; i++){
            for(int j = n - 1; j >= 0; j--){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};