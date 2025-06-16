class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        int diff = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] < x){
                x = nums[i];
            }
            diff = max(diff, nums[i] - x);
        }

        return diff == 0 ? -1 : diff;
    }
};