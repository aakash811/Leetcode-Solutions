class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> ump;
        for (int i = 0; i < s.size(); i++) {
            ump[s[i]] = i;
        }

        vector<int> res;
        int st = 0, en = 0;

        for (int i = 0; i < s.size(); i++) {
            en = max(en, ump[s[i]]);
            if (i == en) {
                res.push_back(en - st + 1);
                st = i + 1;
            }
        }

        return res;
    }
};