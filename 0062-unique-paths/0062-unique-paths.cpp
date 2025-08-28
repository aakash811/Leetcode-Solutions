class Solution {
public:
    int solve(vector<vector<int>> &dp, int m, int n, int i, int j){
        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = 0;
        int down = 0;

        if(i < m - 1){
            right = solve(dp, m, n, i + 1, j);
        }
        if(j < n - 1){
            down = solve(dp, m, n, i, j + 1);
        }

        dp[i][j] = right + down;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(dp, m, n, 0, 0);
    }
};