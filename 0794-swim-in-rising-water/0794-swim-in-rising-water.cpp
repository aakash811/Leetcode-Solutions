class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<pair<int, int>>directions = {{0, 1}, {1,0}, {0,-1}, {-1,0}};

        set<pair<int, int>>vis;
        pq.push({grid[0][0],{0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int maxi = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(vis.count({row, col})){
                continue;
            }
            vis.insert({row, col});

            if(row == n - 1 && col == m - 1){
                return maxi;
            }

            for(auto it : directions){
                int dr = it.first;
                int dc = it.second;

                int drow = dr + row;
                int dcol = dc + col;

                if(drow >= 0 && drow < n && dcol >= 0 && dcol < m && !vis.count({drow, dcol})){
                    int hgt = max(maxi, grid[drow][dcol]);
                    pq.push({hgt, {drow, dcol}});
                }
            }
        }
        return -1;
    }
};