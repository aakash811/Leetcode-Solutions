class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};
        
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int drow = row + dx[i];
                int dcol = col + dy[i];

                if(drow < n && dcol < m && dcol >= 0 && drow >= 0){
                    int eff = max(abs(heights[row][col] - heights[drow][dcol]), d);
                    if(eff < dist[drow][dcol]){
                        dist[drow][dcol] = eff;
                        pq.push({dist[drow][dcol], {drow, dcol}});
                    }
                }
            }
        }

        // for(auto it : dist){
        //     for(auto jt : it){
        //         cout<<jt<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return dist[n - 1][m - 1] != 1e9 ? dist[n - 1][m - 1] : 0;        
    }
};