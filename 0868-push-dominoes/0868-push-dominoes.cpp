class Solution {
public:
    void solve(vector<char>& stk, bool isR, vector<char>& res){
        if (!isR) {
                res.insert(res.end(), stk.begin(), stk.end());
            } else {
                for (int i = 0; i < stk.size(); ++i) {
                    res.push_back('R');
                }
            }
        stk.clear();
    }
    string pushDominoes(string dominoes) {
        vector<char> res;
        vector<char> stk;
        bool isR = false;

        for (char it : dominoes) {
            if (it == '.') {
                stk.push_back('.');
                continue;
            }

            if (it == 'L') {
                stk.push_back('L');
                if (!isR) {
                    for (char c : stk) {
                        res.push_back('L');
                    }
                } else {
                    int n = stk.size();
                    for (int i = 0; i < n / 2; ++i) {
                        res.push_back('R');
                    }
                    if (n % 2 != 0) {
                        res.push_back('.');
                    }
                    for (int i = 0; i < n / 2; ++i) {
                        res.push_back('L');
                    }
                    isR = false;
                }
                stk.clear();
            }

            if (it == 'R') {
                solve(stk, isR, res);
                stk.push_back('R');
                isR = true;
            }
        }
        solve(stk, isR, res);

        return string(res.begin(), res.end());
    }
};