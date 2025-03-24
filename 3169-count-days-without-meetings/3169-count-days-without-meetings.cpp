class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> vec;
        for (auto it : meetings) {
            if (vec.empty() || it[0] > vec.back()[1]) {
                vec.push_back(it);
            } else {
                vec.back()[1] = max(vec.back()[1], it[1]);
            }
        }

        int cnt = 0;
        for (auto it : vec) {
            cnt += (it[1] - it[0] + 1);
        }

        return days - cnt;
    }
};