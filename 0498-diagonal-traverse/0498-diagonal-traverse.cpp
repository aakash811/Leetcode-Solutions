class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int size = n * m;

        vector<int>res(size);
        int row = 0, col = 0;

        for(int i = 0; i < size; i++){
            res[i] = mat[row][col];

            if((row + col) % 2 == 0){
                if(col == m - 1){
                    row++;
                }
                else if(row == 0){
                    col++;
                }
                else{
                    row--;
                    col++;
                }
            }
            else{
                if(row == n - 1){
                    col++;
                }
                else if(col == 0){
                    row++;   
                }
                else{
                    row++;
                    col--;
                }
            }
        }
        return res;
    }
};