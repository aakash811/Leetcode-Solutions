class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int>dp(m + 1, 0);

        for(int i = 1; i <= n; i++){
            vector<int>prev(m + 1, 0);
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]){
                    prev[j] = 1 + dp[j - 1];
                }
                else{
                    prev[j] = max(dp[j], prev[j - 1]);
                }
            } 
            dp = prev;
        }
        return dp[m];
    }
};