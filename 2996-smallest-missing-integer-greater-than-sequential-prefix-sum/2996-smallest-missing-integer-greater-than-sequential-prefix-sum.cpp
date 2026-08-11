class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1] + 1){
                sum += nums[i];
            }
            else{
                break;
            }
        }

        int miss = sum;
        sort(nums.begin(), nums.end());
        for(int j = 0; j < n; j++){
            if(nums[j] == miss){
                miss++;
            }
        }

        return miss;
    }
};