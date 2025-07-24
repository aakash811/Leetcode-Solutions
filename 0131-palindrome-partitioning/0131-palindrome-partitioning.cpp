class Solution {
public:
    bool isPalindrome(string s, int st, int en){
        while(st <= en){
            if(s[st] != s[en]){
                return false;
            }
            st++;
            en--;
        }
        return true;
    }

    void solve(string s, vector<string>& ds, vector<vector<string>>& res, int idx){
        if(idx == s.size()){
            res.push_back(ds);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                ds.push_back(s.substr(idx, i - idx + 1));
                solve(s, ds, res, i + 1);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ds;

        solve(s, ds, res, 0);
        return res;
    }
};