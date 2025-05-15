class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int idx = -1;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] != idx) {
                idx = groups[i];
                res.push_back(words[i]);
            }
        }
        return res;
    }
};