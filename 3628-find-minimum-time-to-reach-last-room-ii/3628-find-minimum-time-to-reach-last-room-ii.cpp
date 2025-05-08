class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<pair<int,int>> dirn = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<>> pq;
        pq.emplace(0, 0, 0, 0);

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        while (!pq.empty()) {
            auto [time, x, y, alt] = pq.top();
            pq.pop();

            if (time > minTime[x][y]) continue;
            if (x == n - 1 && y == m - 1) return time;

            for (auto [dx, dy] : dirn) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int wtTime = max(moveTime[nx][ny] - time, 0);
                int cost = (alt % 2 == 0 ? 1 : 2);
                int nxtTime = time + wtTime + cost;

                if (nxtTime < minTime[nx][ny]) {
                    minTime[nx][ny] = nxtTime;
                    pq.emplace(nxtTime, nx, ny, alt + 1);
                }
            }
        }
        return -1;
    }
};