class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        int id = 0;

        while (left <= right && top <= bottom) {
            if (id == 0) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[top][i]);
                }
                top++; 
            } 
            else if (id == 1) {
                for (int i = top; i <= bottom; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--; 
            } 
            else if (id == 2) { 
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            } 
            else if (id == 3) { 
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++; 
            }
            id = (id + 1) % 4; 
        }
        return res;
    }
};