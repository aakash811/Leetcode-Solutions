class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long tot_pairs = (long long)n * (n - 1) / 2;
        unordered_map<int, long long> ump;
        for (int i = 0; i < n; i++) {
            int x = nums[i] - i;
            tot_pairs -= ump[x];
            ump[x]++;
        }
        return tot_pairs;
    }
};