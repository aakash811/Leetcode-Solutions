class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        
        if(m == 0 || n == 0){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int idx = m - 1;
        int cnt = 0;
        for(int i = n - 1; i >= 0 && idx >= 0; i--){
            if(g[i] <= s[idx]){
                cnt++;
                idx--;
            }
        }

        return cnt;
    }
};