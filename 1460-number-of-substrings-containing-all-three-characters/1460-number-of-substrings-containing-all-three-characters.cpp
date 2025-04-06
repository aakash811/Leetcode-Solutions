class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int>vec = {-1, -1, -1};
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            vec[s[i] - 'a'] = i;
            cnt += 1 + min({vec[0], vec[1], vec[2]});
        }
        return cnt;
    }
};