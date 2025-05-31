class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> rolls(n * n + 1, -1);
        queue<int> q;
        rolls[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            for (int i = 1; i <= 6 && num + i <= n * n; i++) {
                int t = num + i, row = (t - 1) / n, col = (t - 1) % n;
                int val = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                int res = val > 0 ? val : t; 
                if (res == n * n)
                    return rolls[num] + 1;
                if (rolls[res] == -1) {
                    rolls[res] = rolls[num] + 1;
                    q.push(res);
                }
            }
        }
        return -1;
    }
};