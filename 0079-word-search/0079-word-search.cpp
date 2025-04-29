class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int idx, int m, int n, vector<int>& dx, vector<int>& dy, vector<vector<bool>>& vis) {
        if(idx == word.size()){
            return true;
        }

        vis[i][j] = true;
        for(int k = 0; k < 4; k++){
            int dr = i + dx[k];
            int dc = j + dy[k];

            if(dr >= 0 && dr < m && dc >= 0 && dc < n && board[dr][dc] == word[idx] && !vis[dr][dc]){
                if(solve(board, word, dr, dc, idx + 1, m, n, dx, dy, vis)) {
                    return true; 
                }
            }
        }

        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>>vis(m, vector<bool>(n, false));
                    if(solve(board, word, i, j, 1, m, n, dx, dy, vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
