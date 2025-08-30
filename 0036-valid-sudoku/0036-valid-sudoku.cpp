class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            unordered_set<char> vis;
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    if (vis.count(board[i][j])) {
                        return false;
                    }
                    vis.insert(board[i][j]);
                }
            }
        }

        for (int j = 0; j < m; j++) {
            unordered_set<char> vis;
            for (int i = 0; i < n; i++) {
                if (board[i][j] != '.') {
                    if (vis.count(board[i][j])) {
                        return false;
                    }
                    vis.insert(board[i][j]);
                }
            }
        }

        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < m; j += 3) {
                unordered_set<char> vis;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] != '.') {
                            if (vis.count(board[x][y])) {
                                return false;
                            }
                            vis.insert(board[x][y]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
