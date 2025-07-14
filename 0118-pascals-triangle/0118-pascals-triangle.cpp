class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec;

        for(int i = 1 ; i <= numRows; i++){
            int col = 1;
            vector<int>row;
            for(int j = 1; j <= i; j++){
                row.push_back(col);
                col = col * (i - j) / j;
            }
            vec.push_back(row);
        }
        return vec;
    }
};