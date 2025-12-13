class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();

        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= numCarpets; j++) {
                int notTake = (floor[i] == '1') + dp[i + 1][j];
                int take = INT_MAX;
                if (j > 0) {
                    take = dp[min(n, i + carpetLen)][j - 1];
                }

                dp[i][j] = min(notTake, take);
            }
        }

        return dp[0][numCarpets];
    }
};
