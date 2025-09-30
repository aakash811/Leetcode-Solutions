class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        vector<int>res;
        for(int i = 0; i < n - 1; i++){
            int sum = (nums[i] + nums[i + 1]) % 10;
            res.push_back(sum);
        }

        return triangularSum(res);
    }
};