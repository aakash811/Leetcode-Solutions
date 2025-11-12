class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = count(nums.begin(), nums.end(), 1);
        if (cnt1 > 0)
        {
            return n - cnt1;
        }

        int minOps = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i + 1; j < n; j++) {
                x = gcd(x, nums[j]);
                if (x == 1) {
                    minOps = min(minOps, j - i);
                    break;
                }
            }
        }
        if (minOps == INT_MAX)
            return -1;
        return minOps + (n - 1);
    }
};