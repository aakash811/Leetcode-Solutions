class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int freq[2][128] = {};
        freq[0]['a'] = freq[0]['e'] = freq[0]['i'] = freq[0]['o'] = freq[0]['u'] = 1;

        long long res = 0;
        int currK = 0, vows = 0, exL = 0, l = 0;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if (freq[0][ch]) {
                if (++freq[1][ch] == 1) vows++;
            } else {
                currK++;
            }

            while (currK > k) {
                char ch = word[l++];
                if (freq[0][ch]) {
                    if (--freq[1][ch] == 0) vows--;
                } else {
                    currK--;
                }
                exL = 0;
            }

            while (vows == 5 && currK == k && l < i && freq[0][word[l]] && freq[1][word[l]] > 1) {
                exL++;
                freq[1][word[l++]]--;
            }

            if (currK == k && vows == 5) {
                res += (1 + exL);
            }
        }

        return res;
    }
};