class Solution {
public:
    void solve(vector<int>& nums, int sum, int idx, int& xorSum){
        if(idx == nums.size()){
            xorSum += sum;
            return;
        }
        sum ^= nums[idx];
        solve(nums, sum, idx + 1, xorSum);
        sum ^= nums[idx];
        solve(nums, sum, idx + 1, xorSum);
        return;
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int xorSum = 0;
        solve(nums, sum, 0, xorSum);
        return xorSum;
    }
};