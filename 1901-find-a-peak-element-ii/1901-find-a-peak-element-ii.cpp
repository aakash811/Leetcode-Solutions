class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int lo = 0, hi = m - 1;
        while(lo <= hi)
        {
            int maxRow = 0;
            int mid = lo + (hi - lo) / 2;

            for(int i = 0; i < n; i++)
            {
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow = i;
                }
            }
            int curr = mat[maxRow][mid];
            int left = mid == 0 ? -1 : mat[maxRow][mid - 1];
            int rght = mid == m - 1 ? -1 : mat[maxRow][mid + 1];

            if(curr > left && curr > rght){
                return {maxRow, mid};
            }  
            else if(curr < left){
                hi = mid - 1;
            }
            else{
                lo = mid + 1; 
            }
        }        
        return {-1, -1};
    }
};