class Solution {
public:
    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j){
        if(i < 0 || j < 0){
            if(j < 0){
                return i + 1;
            }
            else{
                return j + 1;
            }
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(dp, s1, s2, i - 1, j - 1);
        }

        int replace = solve(dp, s1, s2, i - 1, j - 1);
        int del = solve(dp, s1, s2, i - 1, j);
        int insert = solve(dp, s1, s2, i, j - 1);

        return dp[i][j] = min({replace, del, insert}) + 1;
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(dp, word1, word2, n - 1, m - 1);
    }
};