class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> dp(m, 0);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) dp[j] = 0;
                else dp[j] += 1;
            }
            
            for (int j = 0; j < m; j++) {
                int minH = dp[j];
                for (int k = j; k >= 0 && minH > 0; k--) {
                    minH = min(minH, dp[k]);
                    ans += minH;
                }
            }
        }
        return ans;
    }
};
