class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;

        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                flag++;
            }
        }

        if(nums[n - 1] > nums[0]){
            flag++;
        }
        return flag <= 1;
    }
};