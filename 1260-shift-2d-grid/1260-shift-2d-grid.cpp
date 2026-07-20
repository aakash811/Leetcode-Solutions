class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int nxm = n * m;
        k %= nxm; 

        vector<vector<int>>res(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int idx = i * m + j;
                int newIdx = (idx + k) % nxm;

                int row = newIdx / m;
                int col = newIdx % m;

                res[row][col] =  grid[i][j];
            }
        }

        return res;
    }
};