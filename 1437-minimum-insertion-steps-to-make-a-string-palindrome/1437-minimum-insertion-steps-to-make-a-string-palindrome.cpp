class Solution {
public:
    int solve(vector<vector<int>>& dp, string &s, int i, int j){
        if(i >= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        return dp[i][j] = s[i] == s[j] ? solve(dp, s, i + 1, j - 1) : 1 + min(solve(dp, s, i + 1, j), solve(dp, s, i, j - 1));
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(dp, s, 0, n - 1);
    }
};