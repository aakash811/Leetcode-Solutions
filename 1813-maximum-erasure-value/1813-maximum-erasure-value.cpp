class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>ump;
        int lft = 0;
        int rght = 0;
        int maxSum = 0;
        int sum = 0;

        while(rght < n){
            ump[nums[rght]]++;
            sum += nums[rght];

            while(ump[nums[rght]] > 1){
                ump[nums[lft]]--;
                sum -= nums[lft];
                lft++;
            }
            
            maxSum = max(maxSum, sum);
            rght++;
        }
        return maxSum;
    }
};