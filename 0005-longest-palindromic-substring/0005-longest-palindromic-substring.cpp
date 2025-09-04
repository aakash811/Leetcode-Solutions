class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    // string solve(string s, int i, int j, vector<vector<string>>& dp){
    //     if(i > j){
    //         return "";
    //     }

    //     if(i == j){
    //         return string(1, s[i]);
    //     }

    //     if(dp[i][j] != ""){
    //         return dp[i][j];
    //     }

    //     if(isPalindrome(s, i, j)){
    //         return dp[i][j] = s.substr(i, j - i + 1);
    //     }

    //     string left = solve(s, i + 1, j, dp);
    //     string right = solve(s, i, j - 1, dp);

    //     return dp[i][j] = (left.size() >= right.size()) ? left : right;
    // }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        for(int len = 3; len <= n; len++){
            for(int i = 0; i  <= n - len; i++){
                int j = i + len - 1;

                if(s[i] == s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;

                    if(len > maxLen){
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
        // return solve(s, 0, n - 1, dp);
    }
};