class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMin = 0;
        int currMax = 0;
        int minSum = nums[0];
        int maxSum = nums[0];
        int totalSum = 0;
        
        for(int i = 0; i < n; i++){
            currMax = max(currMax, 0) + nums[i];
            maxSum = max(maxSum, currMax);

            currMin = min(currMin, 0) + nums[i];
            minSum = min(minSum, currMin);

            totalSum += nums[i];
        }

        if(totalSum == minSum){
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};