class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long prxSum = 0, suxSum = 0;

        for (int num : nums) {
            suxSum += num;
        }

        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            prxSum += nums[i];
            suxSum -= nums[i];

            if (prxSum >= suxSum) {
                cnt++;
            }
        }

        return cnt;
    }
};