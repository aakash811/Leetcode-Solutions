class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxi = 0;
        for (int i = 0; i < events.size(); i++) {
            maxi = max(maxi, events[i][1]);
        }

        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());
        int res = 0;
        for (int i = 0, j = 0; i <= maxi; i++) {
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};