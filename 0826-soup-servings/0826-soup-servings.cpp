class Solution {
public:
    double solve(int i, int j, unordered_map<int, unordered_map<int, double>>& dp){
        if(i <= 0 && j <= 0){
            return 0.5;
        }
        if(i <= 0){
            return 1;
        }
        if(j <= 0){
            return 0;
        }
        if(dp[i].count(j)){
            return dp[i][j];
        }
        return dp[i][j] = (solve(i - 4, j, dp) + solve(i - 3, j - 1, dp) + solve(i - 2, j - 2, dp) + solve(i - 1, j - 3, dp)) / 4;
    }

    double soupServings(int n) {
        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;

        for(int k = 1; k <= m; k++){
            if(solve(k, k, dp) > 1 - 1e-5){
                return 1;
            }
        }
        return solve(m, m, dp);
    }
};