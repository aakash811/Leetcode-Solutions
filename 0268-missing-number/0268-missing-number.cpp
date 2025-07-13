class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        int maxi = 0;
        int sum = 0;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            
            sum += nums[i];
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            if(nums[i] < mini){
                mini = nums[i];
            }
        }

        int targ = (maxi * (maxi + 1))/ 2;
        return (mini != 0 ? 0 : (targ == sum ? maxi + 1 : targ - sum)); 
    }
};