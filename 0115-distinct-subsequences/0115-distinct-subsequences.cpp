class Solution {
public:
    // int solve(string &s, string &t, int n, int m, vector<vector<int>>& dp){
    //     if((n == 0 && m == 0) || (m == 0)){
    //         return 1;
    //     }

    //     if(n == 0){
    //         return 0;
    //     }

    //     if(dp[n][m] != -1){
    //         return dp[n][m];
    //     }

    //     if(s[n - 1] == t[m - 1]){
    //         return dp[n][m] = solve(s, t, n - 1, m - 1, dp) + solve(s, t, n - 1, m, dp);
    //     }
    //     return dp[n][m] = solve(s, t, n - 1, m, dp);
    // }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) dp[i][0] = 1;
        for(int j = 1; j <= m; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};