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

        for(int i = 2; i < n - 1; i++){
            int maxi = max(prev + nums[i], curr);
            prev = curr;
            curr = maxi;
        }

        int prev1 = nums[n - 1];
        int curr1 = max(nums[n - 1], nums[n - 2]);

        for(int i = n - 3; i >= 1; i--){
            int maxi1 = max(prev1 + nums[i], curr1);
            prev1 = curr1;
            curr1 = maxi1;
        }

        return max(curr, curr1);
    }
};