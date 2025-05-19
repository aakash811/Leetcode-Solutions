class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();  

        queue<pair<pair<int,int>,int>>q;
        int fresh = 0;
        int time = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        int ans;
        while(!q.empty())
        {
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            time = it.second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && grid[nRow][nCol] == 1)
                {
                    grid[nRow][nCol] = 2;
                    fresh--;
                    q.push({{nRow,nCol},time+1});
                } 
            }
        }

        if(fresh)
        {
            return -1;
        }

        return time;
    }
};