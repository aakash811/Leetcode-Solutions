class Solution 
{
public:
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0; 
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> dirn = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) 
        {
            auto [time, x, y] = pq.top(); pq.pop();

            if (x == m - 1 && y == n - 1)
            {
                return time;
            }
            for (auto it : dirn) 
            {
                int dx = x + it[0];
                int dy = y + it[1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n) 
                {
                    int wtTime = max(0, moveTime[dx][dy] - time);
                    int arTime = time + 1 + wtTime;
                    if (arTime < dist[dx][dy]) 
                    {
                        dist[dx][dy] = arTime;
                        pq.push({arTime, dx, dy});
                    }
                }
            }
        }
        return -1;
    }
};