class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0 || grid[n - 1][n - 1] != 0){
            return -1;
        }

        vector<vector<int>>dist(n, vector<int>(n, 1e9));


        queue<pair<int, int>>q;
        q.push({0, 0});
        dist[0][0] = 1;
        vector<int>dx = {0, 1, 0, -1, 1, -1, 1, -1};
        vector<int>dy = {1, 0, -1, 0, 1, 1, -1, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            if(row == n - 1 && col == n - 1){
                break;
            }
            q.pop();
            
            for(int i = 0; i < 8; i++){
                int drow = row + dx[i];
                int dcol = col + dy[i];

                if(drow < n && dcol < n && drow >= 0 && dcol >= 0 && grid[drow][dcol] == 0){
                    if(dist[row][col] + 1 < dist[drow][dcol]){
                        dist[drow][dcol] = 1 + dist[row][col];
                        q.push({drow, dcol});
                    }
                }
            }
        }
        
        return dist[n - 1][n - 1] != 1e9 ? dist[n - 1][n - 1] : -1;
    }
};