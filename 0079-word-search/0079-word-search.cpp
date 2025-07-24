class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, vector<int>& dx, vector<int>& dy, vector<vector<int>>& vis, int row, int col, int n, int m, int idx){
        if(idx == word.size()){
            return true;
        }

        vis[row][col] = true;
        for(int i = 0; i < 4; i++){
            int dr = row + dx[i];
            int dc = col + dy[i];

            if(dr < n && dr >= 0 && dc < m & dc >= 0 && board[dr][dc] == word[idx] && vis[dr][dc] == false){
                if(solve(board, word, dx, dy, vis, dr, dc, n, m, idx + 1)){
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
                    vector<vector<int>>vis(n, vector<int>(m, false));
                    if(solve(board, word, dx, dy, vis, i, j, n, m, 1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};