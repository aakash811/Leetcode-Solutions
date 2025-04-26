class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0; 
        int idx = -1, minIdx = -1, maxIdx = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                idx = i;
            if (nums[i] == minK)
                minIdx = i;
            if (nums[i] == maxK)
                maxIdx = i;

            int st = min(minIdx, maxIdx);
            res += max(0, st - idx);
        }

        return res;
    }
};