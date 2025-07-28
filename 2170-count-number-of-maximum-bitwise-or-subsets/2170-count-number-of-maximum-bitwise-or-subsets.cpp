class Solution {
public:
    int solve(vector<int>& nums, int idx, int currOr, int target){
        if(idx == nums.size()){
            return (currOr == target) ? 1 : 0;
        }

        int notPick = solve(nums, idx + 1, currOr, target);

        int pick = solve(nums, idx + 1, currOr | nums[idx], target);

        return pick + notPick;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int num : nums){
            maxi |= num;
        }
        return solve(nums, 0, 0, maxi);
    }
};