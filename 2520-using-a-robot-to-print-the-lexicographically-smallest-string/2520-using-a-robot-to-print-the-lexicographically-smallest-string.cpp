class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        int low = 0;
        string p, t;

        for (auto it : s) {
            freq[it - 'a']++;
        }

        for (auto it : s) {
            t += it;
            freq[it - 'a']--;

            while (low < 25 && freq[low] == 0) {
                low++;
            }

            while (!t.empty() && low >= t.back() - 'a') {
                p += t.back();
                t.pop_back();
            }
        }

        return p;
    }
};