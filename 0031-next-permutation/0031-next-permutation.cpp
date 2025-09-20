class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;

        for(int i = n - 1; i > 0; i--){
            if(nums[i] <= nums[i - 1]){
                continue;
            }
            else{
                flag = true;
                int j = n - 1;
                while(nums[j] <= nums[i - 1]){
                        j--;
                    }
                swap(nums[i - 1], nums[j]);
                reverse(nums.begin() + i, nums.end());
                break;
            }
        }

        if(!flag){
            reverse(nums.begin(), nums.end());
        }
    }
};