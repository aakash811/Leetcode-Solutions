class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        int sum2 = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        for(int i = 0; i < n; i++){
            sum1 += nums[i];
            sum2 += nums[i];

            maxSum = max(maxSum, sum1);
            minSum = min(minSum, sum2);

            if(sum1 < 0){
                sum1 = 0;
            }
            if(sum2 > 0){
                sum2 = 0;
            }
        }

        return abs(minSum) > abs(maxSum) ? abs(minSum) : abs(maxSum);
    }
};