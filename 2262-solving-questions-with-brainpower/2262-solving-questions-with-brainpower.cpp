class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        vector<long long> dp(ques.size(), 0);
        for (int i = ques.size() - 1; i >= 0; i--) {
            int index = i + ques[i][1] + 1;
            if (index < ques.size()) {
                dp[i] = dp[index] + ques[i][0];
            } else {
                dp[i] = ques[i][0];
            }
            if (i < ques.size() - 1) {
                dp[i] = max(dp[i + 1], dp[i]);
            }
        }
        return dp[0];
    }
};