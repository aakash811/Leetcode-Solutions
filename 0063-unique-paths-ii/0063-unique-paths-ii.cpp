class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));

        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
            if(dp[i][0] == 0){
                continue;
            }
            else{   
                if(dp[i - 1][0] == 0){
                    dp[i][0] = 0;
                }
                else{
                    dp[i][0] = 1;
                }
            }
        }
        for(int i = 1; i < m; i++){
            if(dp[0][i] == 0){
                continue;
            }
            else{
                if(dp[0][i - 1] == 0){
                    dp[0][i] = 0;
                }else{
                    dp[0][i] = 1;
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(dp[i][j] == 0){
                    continue;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};