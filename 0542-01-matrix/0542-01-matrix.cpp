class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    res[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int dr = r + dx[i];
                int dc = c + dy[i];
                if(dr >= 0 && dr < n && dc >= 0 && dc < m && !vis[dr][dc]){
                    res[dr][dc] = res[r][c] + 1;
                    vis[dr][dc] = true;
                    q.push({dr, dc});
                }
            }
        }
        
        return res;
    }
};
