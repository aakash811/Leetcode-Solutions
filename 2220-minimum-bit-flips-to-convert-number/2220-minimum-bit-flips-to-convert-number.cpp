class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xory = start ^ goal;
        return __builtin_popcount(xory);
    }
};