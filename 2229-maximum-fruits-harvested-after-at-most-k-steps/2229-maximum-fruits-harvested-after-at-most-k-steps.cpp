class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxFruits = 0;
        int total = 0;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            total += fruits[j][1];

            while (i <= j && !canReach(fruits, i, j, startPos, k)) {
                total -= fruits[i][1];
                ++i;
            }

            maxFruits = max(maxFruits, total);
        }

        return maxFruits;
    }

private:
    bool canReach(const vector<vector<int>>& fruits, int i, int j, int startPos, int k) {
        int left = fruits[i][0];
        int right = fruits[j][0];
        int dist1 = abs(startPos - left) + (right - left);
        int dist2 = abs(startPos - right) + (right - left);
        return min(dist1, dist2) <= k;
    }
};
