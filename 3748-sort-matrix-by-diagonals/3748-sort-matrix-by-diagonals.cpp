class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, deque<int>>ump;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ump[i - j].push_back(grid[i][j]);
            }    
        }

        for(auto &it : ump){
            if(it.first < 0){
                sort(it.second.begin(), it.second.end());
            }
            else{
                sort(it.second.rbegin(), it.second.rend());
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = ump[i - j].front();
                ump[i - j].pop_front();
            }
        }

        return grid;
    }
};