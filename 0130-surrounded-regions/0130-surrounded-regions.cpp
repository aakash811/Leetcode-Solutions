class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 'O') {
            return;
        }
        board[row][col] = '#'; 
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            dfs(board, row + dx[i], col + dy[i], n, m);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0, n, m);
            if (board[i][m - 1] == 'O') dfs(board, i, m - 1, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j, n, m);
            if (board[n - 1][j] == 'O') dfs(board, n - 1, j, n, m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
