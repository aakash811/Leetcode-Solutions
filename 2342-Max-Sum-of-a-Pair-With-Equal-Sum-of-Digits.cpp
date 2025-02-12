class Solution {
public:
    int solve(int x) {
        int sum = 0;  
        while(x > 0) {
            sum += x % 10;  
            x /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        vector<vector<int>>vec(82);  
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int res = solve(nums[i]);
            vec[res].push_back(nums[i]);
        }
        
        int maxSum = -1;  
        for(int i = 0; i < 82; i++) {
            if(vec[i].size() > 1) {
                sort(vec[i].begin(), vec[i].end());
                int size = vec[i].size();
                maxSum = max(maxSum, vec[i][size-1] + vec[i][size-2]);
            }
        }
        return maxSum;
    }
};