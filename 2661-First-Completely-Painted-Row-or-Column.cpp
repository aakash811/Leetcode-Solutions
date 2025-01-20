class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int sz = arr.size();

        vector<int>rowVector(n, 0);
        vector<int>colVector(m, 0);

        vector<pair<int,int>>coords(sz);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int num = mat[i][j];
                coords[num - 1] = {i, j};
            }
        }

        int rowCnt = 0;
        int colCnt = 0;

        bool rowFlag = true, colFlag = true; 

        for(int i = 0; i < sz; i++)
        {
            int num = arr[i];
            int rowCord = coords[num - 1].first;
            int colCord = coords[num - 1].second;

            rowVector[rowCord]++;
            colVector[colCord]++;
            if(rowVector[rowCord] == m && rowFlag)
            {
                rowCnt = i;
                rowFlag = false;
            }
            if(colVector[colCord] == n && colFlag)
            {
                colCnt = i;
                colFlag = false;
            }
        }

        return min(rowCnt, colCnt);
    }
};