class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int MAXN = 200005;
        static vector<int> freq(MAXN), preSum(MAXN);

        int maxVal = (*max_element(nums.begin(), nums.end()));
        int lim = (maxVal + k + 2);
        fill(freq.begin(), freq.begin() + lim, 0);

        for (int num : nums) {
            freq[num]++;
        }

        if (numOperations == 0) {
            return (*max_element(freq.begin(), freq.begin() + lim));
        } else 
            preSum[0] = freq[0];
            for (int i = 1; i < lim; i++) {
                preSum[i] = (preSum[i - 1] + freq[i]);
            }

            int best = 0;

            for (int target = 0; target <= maxVal; target++) {
                int left;
                if (target > k) {
                    left = (target - k);
                } else {
                    left = 0;
                }

                int right;
                if ((target + k) < lim) {
                    right = (target + k);
                } else {
                    right = (lim - 1);
                }

                int total = (preSum[right] - ((left > 0) ? preSum[left - 1] : 0));
                int changeable = (total - freq[target]);

                int possible;
                if (numOperations < changeable) {
                    possible = (freq[target] + numOperations);
                } else {
                    possible = (freq[target] + changeable);
                }

                if (possible > best) {
                    best = possible;
                }
            }

        return best;
    }
};