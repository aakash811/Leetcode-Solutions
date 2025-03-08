class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0, res = INT_MAX;
        
        for (int i = 0; i < blocks.size(); i++) 
        {
            if (i - k >= 0 && blocks[i - k] == 'B')
            {
                cnt--;
            } 
            if (blocks[i] == 'B')
            {
                cnt++;
            } 
            res = min(res, k - cnt);
        }
        
        return res;
    }
};