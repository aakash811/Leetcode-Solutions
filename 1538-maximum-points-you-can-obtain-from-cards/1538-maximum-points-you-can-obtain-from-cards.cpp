class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int c : cardPoints) total += c;

        if (k == n) return total;

        int windowSize = n - k;
        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return total - minWindowSum;
    }
};
