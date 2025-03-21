class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int idx, int m, int n) {
        if(idx == word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i == m || j == n || board[i][j] != word[idx] or board[i][j] == '!'){
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '!';

        bool top = solve(board, word, i - 1, j, idx + 1, m, n);
        bool left = solve(board, word, i, j - 1, idx + 1, m, n);
        bool down = solve(board, word, i + 1, j, idx + 1, m, n);
        bool right = solve(board, word, i, j + 1, idx + 1, m, n);  

        board[i][j] = ch;
        return top || left || down || right;      
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[idx]){
                    if(solve(board, word, i, j, idx, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};