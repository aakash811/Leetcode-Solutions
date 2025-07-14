class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0;
        int bottom = n - 1;
        int lft = 0;
        int rght = m - 1;

        vector<int>res;
        while(top <= bottom && lft <= rght){
            for(int i = lft; i <= rght; i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][rght]);
            }
            rght--;

            if(top <= bottom){
                for(int i = rght; i >= lft; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(lft <= rght){
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][lft]);
                }
                lft++;
            }
        }

        return res;
    }
};