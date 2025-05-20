class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diff(n + 1, 0);
        for (auto it : queries) {
            int lo = it[0];
            int hi = it[1];
            diff[lo] -= 1;
            if (hi + 1 < n){
                diff[hi + 1] += 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (nums[i] > -sum){
                return false;
            }
        }

        return true;
    }
};
