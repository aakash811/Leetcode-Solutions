class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vec, vector<vector<int>>& grid, int color, int delRow[], int delCol[],int initColor)
    {
        int n = grid.size();
        int m = grid[0].size();
        vec[row][col] = color;
        for(int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >=0 && nCol >= 0 && nRow < n && nCol < m && grid[nRow][nCol] == initColor && vec[nRow][nCol] != color)       
            dfs(nRow, nCol, vec, grid, color, delRow, delCol, initColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int initColor = image[sr][sc];
      vector<vector<int>>vec = image;
      int delRow[] = {-1,0,1,0};
      int delCol[] = {0,-1,0,1};

      dfs(sr, sc, vec, image, color, delRow, delCol,initColor);
      return vec;
    }
};