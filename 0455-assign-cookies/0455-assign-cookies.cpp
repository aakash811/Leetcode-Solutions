class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty()){
            return 0;
        }
        int n = g.size();
        int idx = s.size() - 1;
        int cnt = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        for(int i = n - 1; i >= 0 && idx >= 0; i--){
            if(s[idx] >= g[i]){
                cnt++;
                idx--;
            }
        }
        return cnt;
    }
};