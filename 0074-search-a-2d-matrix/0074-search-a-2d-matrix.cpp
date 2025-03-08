class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(n <= m)
        {
            for(int i = 0; i < n; i++)
            {
                auto it = lower_bound(matrix[i].begin(), matrix[i].end(),target); 
                if(it != matrix[i].end() && *it == target)
                {
                    return true;
                }
            }
        }
        else
        {
            for(int j = 0; j < m; j++)
            {
                vector<int> col;
                for (int i = 0; i < n; i++) {
                    col.push_back(matrix[i][j]);
                }
                auto it = lower_bound(col.begin(), col.end(),target); 
                if(it != col.end() && *it == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};