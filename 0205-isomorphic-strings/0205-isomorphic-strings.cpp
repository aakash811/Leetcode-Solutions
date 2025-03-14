class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<char> mps(256, 0);
        vector<char> mpt(256, 0); 

        for (int i = 0; i < s.size(); i++) {
            if (mps[s[i]] == 0 && mpt[t[i]] == 0) {
                mps[s[i]] = t[i];
                mpt[t[i]] = s[i]; 
            } else {
                if (mps[s[i]] != t[i] || mpt[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
