class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int i = 1; i < n; i++){
            triangle[i][0] += triangle[i - 1][0];
        }

        int sz = 1;
        for(int i = 1; i < n; i++){
            triangle[i][sz] += triangle[i - 1][sz - 1];
            sz++;
        }

        for(int i = 2; i < n; i++){
            for(int j = 1; j < triangle[i].size() - 1; j++){
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }

        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};