class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& vis, vector<int>& dx, vector<int>& dy, string word, int row, int col, int n, int m, int idx){
        if(idx == word.size()){
            return true;
        }
        vis[row][col] = true;

        for(int i = 0; i < 4; i++){
            int dr = row + dx[i];
            int dc = col + dy[i];

            if(dr < n && dr >= 0 && dc < m && dc >= 0 && vis[dr][dc] == 0 && board[dr][dc] == word[idx]){
                if(dfs(board, vis, dx, dy, word, dr, dc, n, m, idx + 1)){
                    return true;
                }
            }
        }
        vis[row][col] = 0;
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
                    vector<vector<int>>vis(n, vector<int>(m, 0));
                    if(dfs(board, vis, dx, dy, word, i, j, n, m, 1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};