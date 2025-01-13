class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int totalLength = 0;
        for (char currentChar : s) {
            freq[currentChar - 'a']++;
        }
        for (int it : freq) {
            if (it == 0) continue;
            if (it % 2 == 0) {
                totalLength += 2;
            } else {
                totalLength += 1;
            }
        }
        return totalLength;
    }
};