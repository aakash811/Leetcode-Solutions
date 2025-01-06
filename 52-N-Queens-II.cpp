class Solution {
public:

    bool isSafe(int n, int row, int col, vector<string>& ds)
    {
        int dRow = row;
        int dCol = col;

        while(row >= 0 && col >= 0)
        {
            if(ds[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dCol;
        row = dRow;
        while(col >= 0)
        {
            if(ds[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }

        col = dCol;
        row = dRow;
        while(row < n && col >= 0)
        {
            if(ds[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, vector<string>& ds, vector<vector<string>>& res, int n)
    {
        if(col == n)
        {
            res.push_back(ds);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(isSafe(n, i, col, ds))
            {
                ds[i][col] = 'Q';
                solve(col + 1, ds, res, n);
                ds[i][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string>ds(n);
        vector<vector<string>>res;
        string s(n, '.');

        for(int i = 0; i < n; i++)
        {
            ds[i] = s;
        }
        solve(0, ds, res, n);
        return res.size();
    }
};