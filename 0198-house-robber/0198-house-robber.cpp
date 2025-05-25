class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }

        int prev = nums[0];
        int curr = max(nums[1], nums[0]);

        for(int i = 2; i < n; i++){
            int maxi = max(prev + nums[i], curr);
            prev = curr;
            curr = maxi;
        }

        return curr;
    }
};