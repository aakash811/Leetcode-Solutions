class Solution {
public:
    bool solve(vector<vector<char>>& board, vector<vector<bool>>& vis, string word, vector<int>& dx, vector<int>& dy, int row, int col, int n, int m, int idx){
        if(idx == word.size()){
            return true;
        }
        vis[row][col] = true;

        for(int i = 0; i < 4; i++){
            int drow = row + dx[i];
            int dcol = col + dy[i];

            if(drow < n && drow >= 0 && dcol < m && dcol >= 0 && board[drow][dcol] == word[idx] && vis[drow][dcol] == false){
                if(solve(board, vis, word, dx, dy, drow, dcol, n, m, idx + 1)){
                    return true;
                }
            }
        }
        vis[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>>vis(n, vector<bool>(m, false));
                    if(solve(board, vis, word, dx, dy, i, j, n, m, 1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};