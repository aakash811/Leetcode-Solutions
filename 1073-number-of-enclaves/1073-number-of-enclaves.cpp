class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<int>& dx, vector<int>& dy, int row, int col, int n, int m){
        grid[row][col] = 2;
        for(int i = 0; i < 4; i++){
            int dr = row + dx[i];
            int dc = col + dy[i];

            if(dr < n && dr >= 0 && dc < m && dc >= 0 && grid[dr][dc] == 1){
                dfs(grid, dx, dy, dr, dc, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};

        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                dfs(grid, dx, dy, i, 0, n, m);
            }
            if(grid[i][m - 1] == 1){
                dfs(grid, dx, dy, i, m - 1, n, m);
            }
        }

        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1){
                dfs(grid, dx, dy, 0, i, n, m);
            }
            if(grid[n - 1][i] == 1){
                dfs(grid, dx, dy, n - 1, i, n, m);
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};