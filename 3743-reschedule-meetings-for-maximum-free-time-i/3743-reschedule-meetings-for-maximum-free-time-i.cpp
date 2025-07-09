class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int res = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += endTime[i] - startTime[i];
            int lft = i <= k - 1 ? 0 : endTime[i - k];
            int rght = i == n - 1 ? eventTime : startTime[i + 1];
            res = max(res, rght - lft - sum);

            if(i >= k - 1){
                sum -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }

        return res;
    }
};