class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0)
        {
            return 0;
        }

        int currF = grid[row][col];
        grid[row][col] = 0;
        currF += solve(row + 1, col, grid);
        currF += solve(row - 1, col, grid);
        currF += solve(row, col + 1, grid);
        currF += solve(row, col - 1, grid);
        return currF;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxFish = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] != 0) {
                    maxFish = max(maxFish, solve(row, col, grid));
                }
            }
        }
        return maxFish;
    }
};