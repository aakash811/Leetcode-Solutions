class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;
        for (auto it : words) {
            ump[it]++;
        }

        int len = 0;
        bool flag = false;

        for (auto it : ump) {
            string word = it.first;
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                int pairs = ump[word] / 2;
                len += pairs * 4;
                if (ump[word] % 2 == 1) flag = true;
            } else if (word < rev && ump.count(rev)) {
                int pairs = min(ump[word], ump[rev]);
                len += pairs * 4;
            }
        }

        if (flag) len += 2;

        return len;
    }
};
