class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int idx = 0;
        int cnt = 0;
        for(int i = 0; i < n && idx < m; i++){
            if(g[i] <= s[idx]){
                cnt++;
                idx++;
            }
        }
        return cnt;
    }
};