class Solution {
public:
    int n, m;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                dfs(heights, vis, newRow, newCol);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) dfs(heights, vis1, i, 0);
        for (int j = 0; j < m; j++) dfs(heights, vis1, 0, j);

        for (int i = 0; i < n; i++) dfs(heights, vis2, i, m - 1);
        for (int j = 0; j < m; j++) dfs(heights, vis2, n - 1, j);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis1[i][j] && vis2[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
