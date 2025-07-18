class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;
        for(int i = 1; i < n; i++){
            int diff = abs(nums[i] - nums[i - 1]);
            maxDiff = max(maxDiff, diff);
        }

        maxDiff = max(maxDiff, abs(nums[n - 1] - nums[0]));
        return maxDiff;
    }
};