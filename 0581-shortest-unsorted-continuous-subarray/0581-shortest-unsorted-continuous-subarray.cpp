class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        int x = -1, y = -1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            if(nums[i] < maxi){
                y = i;
            }
        }

        for(int i = n - 1; i >= 0; i--){
            mini = min(mini, nums[i]);
            if(nums[i] > mini){
                x = i;
            }
        }

        return (x != -1 && y != -1) ? y - x + 1 : 0;
    }
};