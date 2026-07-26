class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(nums[n - 1] < 0){
            return nums[n - 1] * nums[n - 2] * nums[n - 3];
        }
        else{
            int x = nums[n - 1], y, z;        
            if(nums[n - 1] > 0 && nums[n - 2] > 0 && nums[n - 3] > 0){
                if(nums[n - 2] * nums[n - 3] > abs(nums[0] * nums[1])){
                    y = nums[n - 2];
                    z = nums[n - 3];
                }
                else{
                    y = nums[0];
                    z = nums[1];
                }
            }
            else{
                y = nums[0];
                z = nums[1];
            }

            return x * y * z;
        }
    }
};