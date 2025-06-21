class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        vector<int> freqs;
        for (auto& p : freqMap) {
            freqs.push_back(p.second);
        }

        sort(freqs.begin(), freqs.end());

        int minDel = INT_MAX;
        int n = freqs.size();

        for (int i = 0; i < n; ++i) {
            int targetMin = freqs[i];
            int del = 0;

            for (int j = 0; j < i; ++j) {
                del += freqs[j];
            }

            for (int j = i; j < n; ++j) {
                if (freqs[j] > targetMin + k) {
                    del += freqs[j] - (targetMin + k);
                }
            }

            minDel = min(minDel, del);
        }

        return minDel;
    }
};
