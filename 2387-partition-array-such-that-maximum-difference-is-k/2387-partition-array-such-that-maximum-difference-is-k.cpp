class Solution {
public:
    static int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int parts = 0, n = nums.size();
        for(int i = 0; i < n; ){
            i = upper_bound(nums.begin() + i, nums.end(), nums[i] + k) - nums.begin();
            parts++;
        }
        return parts;
    }
};