class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>hshMap((n * n) + 1, 0);
        hshMap[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x = grid[i][j];
                hshMap[x]++;
            }
        }
        int mis = 0;
        int rep = 0;
        for(int i = 0; i <= n * n; i++)
        {
            if(hshMap[i] == 2){
                rep = i;
            }
            if(hshMap[i] == 0){
                mis = i;
            }
            if(rep && mis){
                break;
            }
        }

        return {rep, mis};
    }
};