class Solution {
public:
    int bs (vector<vector<int>>& events, int curr){
        int lo = 0, hi = events.size() - 1;
        int res = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(events[mid][1] < curr){
                res = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return res;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));

        for(int i = 1; i <= n; i++){
            int prev = bs(events, events[i - 1][0]);

            for(int j = 1; j <= k; j++){
                dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
};